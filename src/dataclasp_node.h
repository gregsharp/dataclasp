/* -----------------------------------------------------------------------
   See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
   ----------------------------------------------------------------------- */
#ifndef _dataclasp_node_h_
#define _dataclasp_node_h_

#include <list>
#include <map>
#include <string>

class Dataclasp_node {
public:
    typedef std::string Leaf_data;
    typedef std::list<Dataclasp_node> Sequence_data;
    typedef std::map<std::string,Dataclasp_node> Map_data;
    enum Type {
        EMPTY_NODE,
        LEAF_NODE,
        SEQUENCE_NODE,
        MAP_NODE
    } type;
    void *data;
public:
    Dataclasp_node ();
    ~Dataclasp_node ();
    void clear ();
};

#endif
