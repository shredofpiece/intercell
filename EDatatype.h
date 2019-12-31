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

/*class Spo  // ShortPos positive unsigned short int
  {
  unsigned short int* m_spo;
 public:
  Spo();
  Spo(unsigned short int spo);
  ~Spo();
  //operator int() const;  // Konversion
  Spo &operator=(const Spo &b);  // Zuweisung
  Spo &operator++();  // In-/Dekrement
  Spo &operator++(int praefix);
  Spo &operator--();
  Spo &operator--(int praefix);
  Spo operator+(const Spo &b) const;  // Die 4 Grundrechenarten
  Spo operator-(const Spo &b) const;
  Spo operator*(const Spo &b) const;
  Spo operator/(const Spo &b) const;
  bool operator==(const Spo &b) const;  // Logik
  bool operator!=(const Spo &b) const;
  bool operator<(const Spo &b) const;
  bool operator>(const Spo &b) const;
  bool operator<=(const Spo &b) const;
  bool operator>=(const Spo &b) const;
  friend ostream &operator<<(ostream &os, Spo &spo);  // Bitshift
  //int Get() const;
  int GetFrom0() const;
  };

class Lpo  // LongPos positive unsigned (long) int
  {
  unsigned long int* m_lpo;
  };

class Wgt  // Weight
  {
  };

class Dey  // Delay
  {
  };

class Vtg  // Voltage
  {
  };*/

// ----------------------------------------------------------------------------

#endif
