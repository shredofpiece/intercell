#include "Main.h"

int main(int argc, char * const argv[])  // alternatives: char * argv[], char **argv, char * const* argv
  {
  cmdargs(&argc,argv);

  // printing debug level, if there is one (+var casts to according int types. here for printing char as number)
  if(debug_level>=1)  cout << "Debug-Level: " << +debug_level << endl << endl << "Netzstruktur aufbauen" << endl << endl;

  Set* p_set = new Set;  // Add set
  // Example network:  Input:      Hidden:      Output:
  //                    (1)          (3)                 // Other example: 64+45+45+27=181
  //                    (2)          (4)          (6)
  //                                 (5)          (7)
  //(*(p_set->HaveNet<Net>(1)))->HaveNode<InputNode>(2);
  (*(p_set->HaveNet<Net>(1)))->HaveNode<PyramidalNode>(5);
  //(*(p_set->HaveNet<Net>(1)))->HaveNode<OutputNode>(7);

  // Schichten:
  //(*(p_set->HaveNet<Net>(1)))->DefineLayer<InputNode>(1,2);
  //(*(p_set->HaveNet<Net>(1)))->DefineLayer<PyramidalNode>(3,5);
  //(*(p_set->HaveNet<Net>(1)))->DefineLayer<OutputNode>(6,7);

  if(debug_level>=1)  cout << endl << "Netzstruktur aufgebaut";

  // Gewünschtere Zugriffsart (like rather preferred way of access):
  // Instance->Net(1)->Node(1)->ToNode(3)->weight += 1;  // typedef ?
  // Instance->Net(1)->Node(4)->ToAxonBetweenNode(5,7)->weight -= 1;
  // Instance->Net(1)->Node(5)->FromDentrideBetweenNode(2,4)->weight += 1;

  // Eigener Datentyp für positive, ganze Zahlen:
    //Spo s1=5, s2=10;
    //Spo s1(5);
  //Spo s1=2;  // Wert von s1.GetInt ehemals: 30237
    //int iii=s1;
  //cout << "############### " << s1 << endl;  // [C++ Fehler] EDatatype.cpp(8): E2094 'operator<<' ist im Typ 'ostream' für Argumente des Typs 'Spo' nicht implementiert
    //cout << "############### " << s1.GetInt() << endl;
    //.operator<<;

  if(debug_level>=1)
    {                 // Dummyinput for preventing the console window
    cin.get();        // from beeing closed automatically in some environments.
    cout << "Netzstruktur abbauen" << endl;
    }
  delete p_set;
  return 0;
  }
