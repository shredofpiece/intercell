#include "CmdArg.h"

void cmdargs(int *argc, char * const argv[])
  {
  // defining global variable debug_level
  if(*argc<2)
    debug_level = 1;
  else
    debug_level=*(argv[1])-48;
  //cout << sizeof(argv[1]) << endl << endl;
  }
