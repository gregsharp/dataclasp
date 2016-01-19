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
    typedef std::list<Dataclasp_node*> Sequence_data;
    typedef std::map<std::string,Dataclasp_node*> Map_data;
    enum Type {
        EMPTY_NODE,
        LEAF_NODE,
        SEQUENCE_NODE,
        MAP_NODE
    };

    std::string name;
    Type type;
    void *value;
    
public:
    Dataclasp_node ();
    Dataclasp_node (const std::string&);
    Dataclasp_node (Dataclasp_node::Type);
    ~Dataclasp_node ();
    void clear ();

    void set_name (const std::string&);
    void set_type (Dataclasp_node::Type);
    void insert_map (const std::string&, const std::string&);
    void insert_map (const std::string&, Dataclasp_node *);
    void print_tree ();
};

#endif
