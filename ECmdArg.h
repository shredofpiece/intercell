#ifndef ECmdArgH
#define ECmdArgH

#include <iostream>             // cin, cout
#include "EDebug.h"             // debug_level
using std::cout;
using std::endl;

//void debug(char* argv);
//void cmdargs(int *argc, char **argv);
void cmdargs(int *argc, char * const argv[]);
//void cmdargs(int *argc, char * const* argv);

#endif
