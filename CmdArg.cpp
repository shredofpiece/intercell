#include "CmdArg.h"

//opterr=1;

/*int main(int argc, char * const argv[])  // alternatives: char * argv[], char **argv, char * const* argv
  {
  ParseOpts(&argc,argv);
  }*/

bool subopterr;

bool SubOptRequiredArgument(const char option[], char* value)
  {
  if(value==NULL)
    {
    cout << "Error: Missing value for suboption '" << option << "'." << endl << "Discarding suboption." << endl;
    subopterr = true;
    return false;
    }
  else
    return true;
  }

bool SubOptOptionalArgument(char* value)
  {
  if(value==NULL)
    {
    return false;
    }
  else
    return true;
  }

void SubOptNoArgument(const char option[], char* value)
  {
  if(value==NULL)
    {
    cout << "Warning: Value '" << value << "' assigned to Non-Value-Suboption '" << option << "'." << endl << "Discarding value." << endl;
    }
  }

bool ParseOpts(int* argc, char *const argv[])  // constant pointer to char array
  {
  while(true)
    {
    // variables for getopt_long
    static struct option long_options[] =  // scope is the while loop
      {
        // {"edge",    required_argument, 0, 'e'},
        // {"layer",    required_argument, 0, 'l'},
        // {"node",    required_argument, 0, 'n'},
        {"opperation", required_argument, 0, 'o'},
        {"verbosity",  optional_argument, 0, 'v'},
        {0, 0, 0, 0}
      };
    int opt;               // char
    int option_index = 0;  // ‘getopt_long’ stores the option index here
    
    // additional variables for getsubopt
    char* subopts;                     
    char* value;
    subopterr = false;  // subopterr = false;  // fatal error -> discarding operation
    debug_level = 1;  // DEFAULT DEBUG LEVEL

    opt = getopt_long (*argc, argv, "o:v::", long_options, &option_index);

    if (opt == -1)  // Schleifenbedingung, diese prüfen  // Detect the end of the options
      break;

    switch (opt)
      {
      case 0:
        if (long_options[option_index].flag != 0)  // If this option set a flag, do nothing else now
          break;
        cout << "Option " << long_options[option_index].name;
        if (optarg>0)
          cout << " with arg " << optarg;
        cout << endl;
        break;

      case 'v':
        {
        cout << "Option -v" << endl;
        // variables for getsubopt
        enum
          {
          QUIET_OPT = 0,  // =0 -> intern value for this name
          VARIABLES_OPT,
          CREATIONS_OPT,
          STRUCTIONS_OPT,
          ADRESSES_OPT
          };
        /*const char * token[] =  // char *const token[] =
          {
          [QUIET_OPT]      = "quiet",
          [VARIABLES_OPT]  = "variables",
          [CREATIONS_OPT]  = "creations",
          [STRUCTIONS_OPT] = "structions",
          [ADRESSES_OPT]   = "adresses",
          NULL
          };*/
        char tok_quiet[] = "quiet";
        char tok_variables[] = "variables";
        char tok_creations[] = "creations";
        char tok_structions[] = "structions";
        char tok_adresses[] = "adresses";
        char *const token[] =
          {
          tok_quiet,
          tok_variables,
          tok_creations,
          tok_structions,
          tok_adresses,
          NULL
          };
        subopts = optarg;
        while (*subopts != '\0')
          {
          switch (getsubopt(&subopts, token, &value))  // const_cast<char *const *>(token)
            {
            case QUIET_OPT:
              SubOptNoArgument(token[QUIET_OPT],value);
              debug_level = 0;
              break;

            case VARIABLES_OPT:
              SubOptNoArgument(token[VARIABLES_OPT],value);
              debug_level = 1;
              break;

            case CREATIONS_OPT:
              SubOptNoArgument(token[CREATIONS_OPT],value);
              debug_level = 2;
              break;

            case STRUCTIONS_OPT:
              SubOptNoArgument(token[STRUCTIONS_OPT],value);
              debug_level = 5;
              break;

            case ADRESSES_OPT:
              SubOptNoArgument(token[ADRESSES_OPT],value);
              debug_level = 6;
              break;

            default:
              cout << "No match found for token: " << value << endl;
              break;
            }
          }
        break;
        }

      case 'o':
        {
        cout << "Option -o with value " << optarg << endl;
        // variables for getsubopt
        enum
          {
          NET_OPT = 0,  // =0 -> intern value for this name
          LAYER_OPT,
          NODE_OPT,
          EDGE_OPT,
          WEIGHT_OPT,
          DELAY_OPT
          };
        const char * token[] =  // char *const token[] =
          {
          [NET_OPT]   = "net",
          [LAYER_OPT]   = "layer",
          [NODE_OPT]   = "node",
          [EDGE_OPT] = "edge",
          [WEIGHT_OPT] = "edge",
          [DELAY_OPT] = "edge",
          NULL
          };

        cnet net = 0;
        clay layer = 0;
        cnde node = 0;
        cedg edge = 0;

        wgt weight = 0.0f;
        dey delay = 0.0f;
        vtg voltage = 0.0f;

        subopts = optarg;
        while (*subopts != '\0' && !subopterr)
          {
          switch (getsubopt(&subopts, const_cast<char *const *>(token), &value))
            {
            case NET_OPT:
              if(SubOptOptionalArgument(value))
                net = stoi(value);
              else
                net = 1;
              break;

            case LAYER_OPT:
              layer = stoi(value);
              break;

            case NODE_OPT:
              if(SubOptRequiredArgument(token[NODE_OPT],value))
                node = stoi(value);
              break;

            case EDGE_OPT:
              if(SubOptRequiredArgument(token[EDGE_OPT],value))
                edge = stoi(value);
              break;

            case WEIGHT_OPT:
              if(SubOptRequiredArgument(token[WEIGHT_OPT],value))
                weight = stoi(value);
              break;

            case DELAY_OPT:
              if(SubOptRequiredArgument(token[DELAY_OPT],value))
                delay = stoi(value);
              break;

            default:
              cout << "No match found for token: " << value << endl;
              break;
            }
          }
        if(subopterr)
          cout << "Command discarded" << endl;
        break;
        }

      case '?':
        break;  // ‘getopt_long’ already printed an error message

      default:
        cout << "Discarding unfetched option: " << opt << endl;
        break;
      }
    }

  // return &argv[optind];

  if (optind < *argc)  // Print any remaining command line arguments (not options)
    {
    cout << "Non-Option ARGumentValues:";
    while (optind < *argc)
      cout << " " << argv[optind++];
    cout << endl;
    }

  if(subopterr)
    return false;
  else
    return true;
  }


/*
void cmdargs(int *argc, char * const argv[])
  {
  // defining global variable debug_level
  if(*argc<2)
    debug_level = 1;
  else
    debug_level=*(argv[1])-48;
  //cout << sizeof(argv[1]) << endl << endl;
  }
*/
