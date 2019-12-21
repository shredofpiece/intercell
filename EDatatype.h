#ifndef EDatatypeH
#define EDatatypeH

#include <iostream>  // Operator overloading, (cout)
#include <limits>
using std::numeric_limits;
using std::ostream;
using std::cout;
using std::endl;

// ----------------------------------------------------------------------------

const unsigned short int USI_MIN=numeric_limits<unsigned short int>::min();  // C++11 for g++ and BCB
const unsigned short int USI_MAX=numeric_limits<unsigned short int>::max();
const unsigned long int ULI_MIN=numeric_limits<unsigned long int>::min();
const unsigned long int ULI_MAX=numeric_limits<unsigned long int>::max();

// ----------------------------------------------------------------------------

typedef unsigned short int usi;
typedef unsigned long int uli;
//typedef signed long int pos;
typedef double wgt;
typedef float dey;
typedef long double vtg;

// ----------------------------------------------------------------------------

#endif
