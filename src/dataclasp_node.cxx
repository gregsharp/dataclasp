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

Dataclasp_node*
Dataclasp_node::add_sequence ()
{
    Dataclasp_node *a = 0;
    return a;
}

void
Dataclasp_node::print_tree ()
{
    
}
