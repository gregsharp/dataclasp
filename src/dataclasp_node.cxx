/* -----------------------------------------------------------------------
   See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
   ----------------------------------------------------------------------- */
#include <stdio.h>
#include <yaml.h>
#include "dataclasp_node.h"

Dataclasp_node::Dataclasp_node ()
{
    type = EMPTY_NODE;
    value = 0;
}

Dataclasp_node::Dataclasp_node (const std::string& s)
{
    name = "";
    type = LEAF_NODE;
    value = new std::string(s);
}

Dataclasp_node::~Dataclasp_node () {
    this->clear ();
}

void
Dataclasp_node::clear ()
{
    switch (type) {
    case EMPTY_NODE:
        break;
    case LEAF_NODE:
        delete (Leaf_data*) value;
        break;
    case SEQUENCE_NODE:
        /* GCS FIX: Delete sequence */
        delete (Sequence_data*) value;
        break;
    case MAP_NODE:
        /* GCS FIX: Delete map value */
        delete (Map_data*) value;
        break;
    }
    type = EMPTY_NODE;
    value = 0;
}

void
Dataclasp_node::set_name (const std::string& name)
{
    this->name = name;
}

void
Dataclasp_node::set_type (Dataclasp_node::Type type)
{
    this->clear ();
    this->type = type;
    switch (type) {
    case EMPTY_NODE:
        break;
    case LEAF_NODE:
        this->value = new Leaf_data;
        break;
    case SEQUENCE_NODE:
        this->value = new Sequence_data;
        break;
    case MAP_NODE:
        this->value = new Map_data;
        break;
    }
}

void
Dataclasp_node::insert_map (const std::string& name, const std::string& value)
{
    if (this->type != MAP_NODE) {
        fprintf (stderr,
            "Program error. Attempted to insert_map into a non-map\n");
    }
    Dataclasp_node *leaf = new Dataclasp_node (value);
    Map_data *md = (Map_data*) this->value;
    (*md)[name] = leaf;
}

void
Dataclasp_node::print_tree ()
{
    
}
