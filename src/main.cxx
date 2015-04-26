/* -----------------------------------------------------------------------
   See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
   ----------------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>
#include "yaml_loader.h"


// YAML tutorial
//   https://www.wpsoftware.net/andrew/pages/libyaml.html
// Alternative languages
//   https://github.com/toml-lang/toml
//   https://www.npmjs.com/package/lcon
//   http://sexpr.sourceforge.net/
// Transport languages+librarires
//   https://developers.google.com/protocol-buffers
//   http://bsonspec.org
//   http://zeromq.org



void
usage ()
{
    printf ("Usage: dataclasp input-file\n");
    exit (-1);
}

int
main (int argc, char *argv[])
{
    if (argc != 2) {
        usage ();
    }

    Yaml_loader yl;
    Dataclasp& dc = yl.get_dataclasp (argv[1]);

    return 0;
}
