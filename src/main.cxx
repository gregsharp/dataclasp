/* -----------------------------------------------------------------------
   See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
   ----------------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>
#include "dataclasp_argv.h"
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
    printf ("Usage: dataclasp [ -O output-file ] input-file\n");
    exit (-1);
}

int
main (int argc, char *argv[])
{
    std::string infile, outfile;
    
    if (argc == 2) {
        infile = argv[1];
    }
    else if (argc == 4) {
        if (std::string(argv[1]) != "-O") {
            usage ();
        }
        outfile = argv[2];
        infile = argv[3];
    }
    else {
        usage ();
    }

    Yaml_loader yl;
    Dataclasp_node *dc = yl.get_dataclasp (infile);

    if (outfile != "") {
        Dataclasp_argv dca (dc);
        dca.write_argv_parser ();
    }

    return 0;
}
