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
print_usage (const char* error_message = 0)
{
    printf (
        "Usage: dataclasp [options] input-file\n"
	"Options:\n"
	" -b backend          Backend used to create output file\n"
	" -O outfile          Output file\n"
    );
    if (error_message) {
        printf ("%s\n", error_message);
    }
    exit (1);
}

int
main (int argc, char *argv[])
{
    Yaml_loader yl;
    std::string backend;
    std::string input_file;
    std::string output_file;

    if (argc == 1) {
	print_usage ();
    }

    int i;
    for (i = 1; i < argc; i++) {
	if (!strcmp (argv[i], "-b")) {
	    if (++i >= argc) { 
                print_usage("Error parsing -b option"); 
            }
	    backend = argv[i];
	}
	else if (!strcmp (argv[i], "-O")) {
	    if (++i >= argc) { 
                print_usage("Error parsing -O option"); 
            }
	    output_file = argv[i];
	}
        else if (!strcmp (argv[i], "-")) {
            print_usage("Error parsing unknown option");
        }
        else {
            break;
        }
    }

    if (i < argc) {
        input_file = argv[i++];
        printf ("Input file is: %s\n", input_file.c_str());
    }
    if (i < argc) {
	print_usage ("Error, extra argument.");
    }

    Dataclasp_node *dc = yl.get_dataclasp (input_file.c_str());

    if (output_file != "") {
        Dataclasp_argv dca (dc);
        dca.write_argv_parser ();
    }

    return 0;
}
