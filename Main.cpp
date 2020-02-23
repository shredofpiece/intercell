#include "Main.h"

int main(int argc, char *const argv[])  // alternatives: char * argv[], char **argv, char * const* argv
  {
  //cmdargs(&argc,argv);
  if(!ParseOpts(&argc,argv))
    return 1;

  // printing debug level, if there is one (+var casts to according int types. here for printing char as number)
  if(debug_level>=1)  cout << "Debug-Level: " << +debug_level << endl << "Netzstruktur aufbauen" << endl << endl;
                                                                                 if(debug_level>=1)  cout << "Adding Set:" << endl << "Set* p_set = new Set;" << endl;
  Set* p_set = new Set;  // Add set
  // Example network:  Input:      Hidden:      Output:
  //                    (1)          (3)                 // Other example: 64+45+45+27=181
  //                    (2)          (4)          (6)
  //                                 (5)          (7)
                                                                                 if(debug_level>=1)  cout << endl << "Adding neurons:" << endl << "(*(p_set->HaveNet<Net>(1)))->HaveNode<ReceptorNode>(2);" << endl;
  (*(p_set->HaveNet<Net>(1)))->HaveNode<ReceptorNode>(2);                        if(debug_level>=1)  cout << endl << "(*(p_set->HaveNet<Net>(1)))->HaveNode<PyramidalNode>(5);" << endl;
  (*(p_set->HaveNet<Net>(1)))->HaveNode<PyramidalNode>(5);                       if(debug_level>=1)  cout << endl << "(*(p_set->HaveNet<Net>(1)))->HaveNode<ActorNode>(7);" << endl;
  (*(p_set->HaveNet<Net>(1)))->HaveNode<ActorNode>(7);

  // Schichten:
                                                                                 if(debug_level>=1)  cout << endl << "Adding Span:" << endl << "(*(p_set->HaveNet<Net>(1)))->DefineSpan<ReceptorNode>(1,2);" << endl;
  (*(p_set->HaveNet<Net>(1)))->DefineSpan<ReceptorNode>(1,2);                    if(debug_level>=1)  cout << endl << "(*(p_set->HaveNet<Net>(1)))->DefineSpan<PyramidalNode>(3,5);" << endl;
  (*(p_set->HaveNet<Net>(1)))->DefineSpan<PyramidalNode>(3,5);                   if(debug_level>=1)  cout << endl << "(*(p_set->HaveNet<Net>(1)))->DefineSpan<PyramidalNode>(6,7);" << endl;
  (*(p_set->HaveNet<Net>(1)))->DefineSpan<ActorNode>(6,7);
                                                                                 if(debug_level>=1)  cout << endl << "Adding Layer:" << endl << "(*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(1)))->HaveNode<ReceptorNode>(1);" << endl;
  (*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(1)))->HaveNode<ReceptorNode>(1);  if(debug_level>=1)  cout << endl << "(*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(1)))->HaveNode<ReceptorNode>(2);" << endl;
  (*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(1)))->HaveNode<ReceptorNode>(2);  if(debug_level>=1)  cout << endl << "(*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(2)))->HaveNode<ReceptorNode>(3);" << endl;
  (*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(2)))->HaveNode<PyramidalNode>(3);  if(debug_level>=1)  cout << endl << "(*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(2)))->HaveNode<ReceptorNode>(4);" << endl;
  (*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(2)))->HaveNode<PyramidalNode>(4);  if(debug_level>=1)  cout << endl << "(*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(2)))->HaveNode<ReceptorNode>(5);" << endl;
  (*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(2)))->HaveNode<PyramidalNode>(5);  if(debug_level>=1)  cout << endl << "(*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(3)))->HaveNode<ReceptorNode>(6);" << endl;
  (*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(3)))->HaveNode<ActorNode>(6);  if(debug_level>=1)  cout << endl << "(*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(3)))->HaveNode<ReceptorNode>(7);" << endl;
  (*((*(p_set->HaveNet<Net>(1)))->HaveLayer<Layer>(3)))->HaveNode<ActorNode>(7);

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
