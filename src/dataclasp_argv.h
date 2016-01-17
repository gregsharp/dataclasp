/* -----------------------------------------------------------------------
   See COPYRIGHT.TXT and LICENSE.TXT for copyright and license information
   ----------------------------------------------------------------------- */
#ifndef _dataclasp_argv_h_
#define _dataclasp_argv_h_

class Dataclasp_node;

class Dataclasp_argv {
public:
    Dataclasp_argv (Dataclasp_node *);
    ~Dataclasp_argv ();
public:
    void write_argv_parser ();
public:
    Dataclasp_node *dc;
};

#endif
