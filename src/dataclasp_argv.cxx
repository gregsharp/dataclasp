/* -----------------------------------------------------------------------
   See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
   ----------------------------------------------------------------------- */
#include <stdio.h>
#include <yaml.h>
#include "dataclasp_argv.h"

Dataclasp_argv::Dataclasp_argv (Dataclasp_node *dc)
{
    this->dc = dc;
}

Dataclasp_argv::~Dataclasp_argv ()
{
}

void
Dataclasp_argv::write_argv_parser ()
{
}
