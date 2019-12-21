#ifndef TDeleteListAndTheirElementsH
#define TDeleteListAndTheirElementsH

#include <iostream>  // cout
#include <list>
#include <typeinfo>  // typeid
//using namespace std;  // list, cout, endl
using std::list;
using std::cout;
using std::endl;

// ----------------------------------------------------------------------------

template <typename D>  // D=Data  // Wenn ausgelagert und Definition im Header: [C++ Warnung] TDeleteListAndTheirElements.cpp(3): W8058 Präcompilierter Header: Header unvollständig kann nicht erzeugt werden
void DeleteListAndTheirElements(list<D*>* l, typename list<D*>::iterator i)
  {                                                                              cout << "DelLstel(list<" << typeid(D).name() << "*>* l: " << l << ", list<" << typeid(D).name() << "*>::iterator i)\tsize " << l->size() << endl;
  if (l->size()>0)                                                               // Bei Ausgabe von uninitialisiertem *i mit g++ Datenzugriffsfehler.
    {
    i = l->end();
    do
      {
      --i;                                                                       cout << "DelLstel(l,i)\tdelete " << *i << endl;
      delete *i;
      }
    while (i!=l->begin());
    }
  delete l;
  }

#endif
