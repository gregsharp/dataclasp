/* -----------------------------------------------------------------------
   See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
   ----------------------------------------------------------------------- */
#ifndef _yaml_loader_h_
#define _yaml_loader_h_

#include "dataclasp.h"

class Yaml_loader {
public:
    Dataclasp_node* dataclasp;
public:
    Yaml_loader ();
    ~Yaml_loader ();
public:
    Dataclasp_node* get_dataclasp (const char* fn);
};

#endif
