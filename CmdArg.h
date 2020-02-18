#ifndef CmdArgH
#define CmdArgH

/*#include <iostream>             // cin, cout

//#include <getopt>
//#include "ParseOpt.h"
#include "Debug.h"             // debug_level
using std::cout;
using std::endl;

//void debug(char* argv);
void cmdargs(int *argc, char * const argv[]);
*/
/*
class CmdArg
  {
 private
  
  };
*/

#include <iostream>  // cin, cout
#include <getopt.h>  // getopt_long
#include <cstdlib>   // getsubopt, exit
using std::cout;
using std::endl;

bool subopterr;
//char* optarg;
//int optint, opterr, optopt;

bool SubOptRequiredArgument(char option[], char* value);
bool SubOptOptionalArgument(char* value);
void SubOptNoArgument(char option[], char* value);

bool ParseOpts(int* argc, char *const argv[]);

#endif
