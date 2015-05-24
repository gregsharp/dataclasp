/* -----------------------------------------------------------------------
   See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
   ----------------------------------------------------------------------- */
#include <stdio.h>
#include <yaml.h>
#include "yaml_loader.h"

Yaml_loader::Yaml_loader ()
{
    dataclasp = 0;
}

Yaml_loader::~Yaml_loader ()
{
    delete dataclasp;
}

Dataclasp_node*
Yaml_loader::get_dataclasp (const char* fn)
{
    printf ("Hello world (from yaml_loader): %s\n", fn);

    yaml_parser_t parser;
    yaml_event_t event;

    FILE *fp = fopen (fn, "rb");

    yaml_parser_initialize (&parser);
    yaml_parser_set_input_file (&parser, fp);

    int num_documents = 0;
    bool done = false;
    bool seeking_value = false;
    std::string key, value;

    dataclasp = new Dataclasp_node;

    std::stack<Dataclasp*> dcl_stack;
    dcl_stack.push (dataclasp);
    current_node = dataclasp;
    
    while (!done) {
        /* Get the next event. */
        if (!yaml_parser_parse (&parser, &event)) {
            fprintf (stderr, "Error parsing YAML file.\n");
            break;
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
            num_documents ++;
        }
        else if (event.type == YAML_DOCUMENT_END_EVENT) {
            /* Do nothing */
        }
        else if (event.type == YAML_ALIAS_EVENT) {
            /* Do nothing */
        }
        else if (event.type == YAML_SCALAR_EVENT) {
            printf ("S: %s | %s\n",
                event.data.scalar.tag ? (const char*) event.data.scalar.tag : "(null)",
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
                event.data.mapping_start.anchor ? (const char*) event.data.mapping_start.anchor : "(null)",
                event.data.mapping_start.tag ? (const char*) event.data.mapping_start.tag : "(null)");
        }
        else if (event.type == YAML_MAPPING_END_EVENT) {
            printf ("M: end\n");
        }
        yaml_event_delete (&event);
    }
    yaml_parser_delete (&parser);
    fclose (fp);
    printf ("Processed %d documents\n", num_documents);

    return dataclasp;
}
