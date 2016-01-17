/* -----------------------------------------------------------------------
   See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
   ----------------------------------------------------------------------- */
#ifndef _yaml_loader_h_
#define _yaml_loader_h_

#include <yaml.h>

#include "dataclasp.h"

class Yaml_loader {
public:
    Dataclasp_node* dataclasp;
    int num_documents;
public:
    Yaml_loader ();
    ~Yaml_loader ();
public:
    Dataclasp_node* get_dataclasp (
        const std::string& infile);
protected:
    bool parse_event (yaml_parser_t *parser);
};

#endif
