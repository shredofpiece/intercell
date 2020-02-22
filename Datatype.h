#ifndef DatatypeH
#define DatatypeH

//#include <iostream>  // (cout), Operator overloading, crossincludes cstdint?
#include <cstdint>   // Datatypes by exact size
#include <limits>
//#include <bitset>
using std::uint8_t;
using std::uint16_t;
using std::uint64_t;
//using std::int64_t;
using std::numeric_limits;
//using std::ostream;
//using std::cout;
//using std::endl;

// ----------------------------------------------------------------------------

typedef uint16_t usi;     // 2*8bit, unsigned short int
typedef uint64_t uli;     // 8*8bit, Mengen (von Elementen), unsigned long long int

// Mengen (von Elementen), amounts (quantities) of elements // cnet<=clay<=cnde<=cedg
typedef uint8_t cnet;  // count of nets
typedef uint8_t clay;  // count of layers
typedef uint64_t cnde; // count of nodes
typedef uint64_t cedg; // count of edges
typedef cedg cnoe;     // count of nodes or edges

//typedef int64_t pos;    // 4*8bit, signed long int
typedef double wgt;       // 8*8bit
typedef float dey;        // 4*8bit
typedef long double vtg;  // 12*8bit
typedef uint8_t dbg;      // 1*8bit, debug level, unsigned short int

// ----------------------------------------------------------------------------

const usi USI_MIN=numeric_limits<usi>::min();
const usi USI_MAX=numeric_limits<usi>::max();
const uli ULI_MIN=numeric_limits<uli>::min();
const uli ULI_MAX=numeric_limits<uli>::max();

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
