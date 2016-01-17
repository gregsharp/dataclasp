/* -----------------------------------------------------------------------
   See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
   ----------------------------------------------------------------------- */
#include <stack>
#include <stdio.h>
#include <yaml.h>
#include "yaml_loader.h"
#include "dataclasp_node.h"

/*
stream ::= STREAM-START document* STREAM-END
document ::= DOCUMENT-START node DOCUMENT-END
node ::= ALIAS | SCALAR | sequence | mapping
sequence ::= SEQUENCE-START node* SEQUENCE-END
mapping ::= MAPPING-START (node node)* MAPPING-END
*/

Yaml_loader::Yaml_loader ()
{
    dataclasp = 0;
    num_documents = 0;
}

Yaml_loader::~Yaml_loader ()
{
    delete dataclasp;
}

Dataclasp_node *
Yaml_loader::parse_yaml_node (
    yaml_parser_t *parser
)
{
    Dataclasp_node *dataclasp = new Dataclasp_node;

    /* Get the next event. */
    bool done = false;
    std::string map_name = "", map_value = "";
    while (!done) {
        yaml_event_t event;
        if (!yaml_parser_parse (parser, &event)) {
            fprintf (stderr, "Error parsing YAML file.\n");
        }
        if (event.type == YAML_NO_EVENT) {
            /* Do nothing */
        }
        else if (event.type == YAML_STREAM_START_EVENT) {
            /* Do nothing */
        }
        else if (event.type == YAML_STREAM_END_EVENT) {
            done = true;
        }
        else if (event.type == YAML_DOCUMENT_START_EVENT) {
            this->num_documents ++;
        }
        else if (event.type == YAML_DOCUMENT_END_EVENT) {
            /* Do nothing */
        }
        else if (event.type == YAML_ALIAS_EVENT) {
            /* Do nothing */
        }
        else if (event.type == YAML_SCALAR_EVENT) {
            printf ("S: %s | %s\n",
                event.data.scalar.tag
                ? (const char*) event.data.scalar.tag : "(null)",
                event.data.scalar.value);
            if (dataclasp->type == Dataclasp_node::MAP_NODE) {
                if (map_name == "") {
                    map_name = (const char*) event.data.scalar.value;
                } else {
                    map_value = (const char*) event.data.scalar.value;
                    dataclasp->insert_map (map_name, map_value);
                    map_name = map_value = "";
                }
            }
        }
        else if (event.type == YAML_SEQUENCE_START_EVENT) {
            printf ("S: start\n");
        }
        else if (event.type == YAML_SEQUENCE_END_EVENT) {
            printf ("S: end\n");
        }
        else if (event.type == YAML_MAPPING_START_EVENT) {
            printf ("M: %s | %s\n",
                event.data.mapping_start.anchor
                ? (const char*) event.data.mapping_start.anchor : "(null)",
                event.data.mapping_start.tag
                ? (const char*) event.data.mapping_start.tag : "(null)");
            dataclasp->set_type (Dataclasp_node::MAP_NODE);
        }
        else if (event.type == YAML_MAPPING_END_EVENT) {
            printf ("M: end\n");
            done = true;
        }
        yaml_event_delete (&event);
    }
    return dataclasp;
}

bool
Yaml_loader::parse_event (
    yaml_parser_t *parser
)
{
    /* Get the next event. */
    yaml_event_t event;
    if (!yaml_parser_parse (parser, &event)) {
        fprintf (stderr, "Error parsing YAML file.\n");
        return true;
    }
    if (event.type == YAML_NO_EVENT) {
        /* Do nothing */
    }
    else if (event.type == YAML_STREAM_START_EVENT) {
        /* Do nothing */
    }
    else if (event.type == YAML_STREAM_END_EVENT) {
        return true;
    }
    else if (event.type == YAML_DOCUMENT_START_EVENT) {
        this->num_documents ++;
    }
    else if (event.type == YAML_DOCUMENT_END_EVENT) {
        /* Do nothing */
    }
    else if (event.type == YAML_ALIAS_EVENT) {
        /* Do nothing */
    }
    else if (event.type == YAML_SCALAR_EVENT) {
        printf ("S: %s | %s\n",
            event.data.scalar.tag
            ? (const char*) event.data.scalar.tag : "(null)",
            event.data.scalar.value);
    }
    else if (event.type == YAML_SEQUENCE_START_EVENT) {
        printf ("S: start\n");
    }
    else if (event.type == YAML_SEQUENCE_END_EVENT) {
        printf ("S: end\n");
    }
    else if (event.type == YAML_MAPPING_START_EVENT) {
        printf ("M: %s | %s\n",
            event.data.mapping_start.anchor
            ? (const char*) event.data.mapping_start.anchor : "(null)",
            event.data.mapping_start.tag
            ? (const char*) event.data.mapping_start.tag : "(null)");
    }
    else if (event.type == YAML_MAPPING_END_EVENT) {
        printf ("M: end\n");
    }
    yaml_event_delete (&event);
    return false;
}

Dataclasp_node*
Yaml_loader::get_dataclasp (
    const std::string& infile)
{
    printf ("Hello world (from yaml_loader): %s\n", infile.c_str());

    yaml_parser_t parser;

    FILE *fp = fopen (infile.c_str(), "rb");

    yaml_parser_initialize (&parser);
    yaml_parser_set_input_file (&parser, fp);

    bool done = false;
    bool seeking_value = false;
    std::string key, value;

    dataclasp = new Dataclasp_node;

    std::stack<Dataclasp_node*> dcl_stack;
    dcl_stack.push (dataclasp);
    Dataclasp_node *current_node = dataclasp;
    
    while (!done) {
        done = this->parse_event (&parser);
    }
    yaml_parser_delete (&parser);
    fclose (fp);
    printf ("Processed %d documents\n", this->num_documents);

    return dataclasp;
}
