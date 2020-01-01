#ifndef EDataStructureH
#define EDataStructureH

#include <iostream>         // cout
//#include <list>
#include <typeinfo>         // typeid
//#include <type_traits>    // is_baseof
#include <boost/ptr_container/ptr_list.hpp>  // newer version of C++? innerhalb boost: [C++ Fehler] remove_cv.hpp(22): E2238 Bezeichner 'remove_cv<T>' mehrfach deklariert
//#include "TDeleteListAndTheirElements.h"
#include "EDatatype.h"
//#include "ETime.h"
#include "EDebug.h"         // debug_level
//using std::list;
using std::cout;
using std::endl;
using boost::ptr_list;

// ----------------------------------------------------------------------------

template <typename B>  // B=Base(Class)  // Als Basisklasse ?
class ObjectCare
  {
  ptr_list<B*>* plp;
  typename ptr_list<B*>::iterator ilp;
 public:
  ObjectCare()
    {                                                                            if(debug_level>=5)  cout << "ObjectCare::ObjectCare()\tKonstruktor" << endl;
    plp = new ptr_list<B*>;
    }
  ~ObjectCare()
    {                                                                            if(debug_level>=5)  cout << "ObjectCare::~ObjectCare()\tDestruktor" << endl;
    //DeleteListAndTheirElements<B>(plp,ilp);  // Mit g++ not declared in this scope, wenn dieser Header in TDeleteListAndTheirElements.h inkludiert
    delete plp;  // Mit g++ not declared in this scope, wenn dieser Header in TDeleteListAndTheirElements.h inkludiert
    }
  template <typename D/*, typename... Args*/>  // D=Data (Type of pointer in ptr_list), C=count
  void AddElement(/*Args... args*/)
    {
    plp->push_back(new D/*(args...)*/);                                                       // [C++ Warnung] EDataStructure.h(20): W8030 Temporäre Größe für Parameter '__x' in Aufruf von 'list<Node *,allocator<Node *> >::push_back(Node * const &)' verwendet
    }
  template <typename D, typename C/*, typename... Args*/>  // D=Data (Type of pointer in ptr_list), C=count,  // A=Arguments (for Constructor)
  typename ptr_list<B*>::iterator HaveElement(C count/*, Args... args*/)
    {                                                                            if(debug_level>=1)  cout << "ObjC::HavEl(" << count << ". Typ: " << typeid(D).name() << ")" << endl << "ObjC::HavEl(" << count << ". Typ: " << typeid(D).name() << ")\tAnfangsobjektanzahl: " << plp->size() << endl;
    while(plp->size()<count)  // Solange Basisgröße kleiner Auswahl              // Wenn Mehrfachvererbung und zusammenführung InnerNode->InputNode, OutputNode->Node anscheinend keine Typkompatibilität von InnerNode zur Liste mit Zeigern auf die Basisklasse Node:
      AddElement<D/*,Args...*/>(/*args...*/);        // Füge Element hinzu
    ilp=plp->begin();         /* Itterator inititialisieren   */                 if(debug_level>=6)  cout << "ObjC::HavEl(" << count << ". Typ: " << typeid(D).name() << ")\tilp = plp->begin(): " << *ilp << endl;
    advance(ilp, count-1);    /* Auf Auswahl Zeigen           */                 if(debug_level>=1)  cout << "ObjC::HavEl(" << count << ". Typ: " << typeid(D).name() << ")\tEndobjektanzahl: " << plp->size() << endl;  if(debug_level>=6)  cout << "ObjC::HavEl(" << count << ". Typ: " << typeid(D).name() << ")\tAdr. 1.\tObjekt: " << *(plp->begin()) << endl << "ObjC::HavEl(" << count << ". Typ: " << typeid(D).name() << ")\tAdr. " << count << ".\tObjekt: " << *ilp << " (Rueckgabe)" << endl;
    return ilp;               // Zeig auf Auswahl zurückgeben
    }
  };

// ----------------------------------------------------------------------------

class Node;

//class Hormon // (Neuro)hormone distribution  // parakrin, neuroendokrin (z.B chemisches rufen nach axonalen synapsen)

class Edge  // Synaptic gap, synapses (weight), axon, dentride
  {
 protected:
  wgt* mp_weight;
  //pos* mp_pos_x, mp_pos_y, mp_pos_z;
  dey* mp_delay;
 public:
  Edge(wgt weight=0.0, dey delay=0.0);
  virtual ~Edge()=0;  // =0: pure: Kein eigenständiges Objekt
  wgt GetWeight() const;
  dey GetDelay() const;
  };

class NodeEdge_Edge : public Edge  // Axo-axonic synapse
  {
 protected:
  Node* mp_source;
  Edge* mp_dest;  // temporary influence(increase, also decrease?) on weight of dest edge (STP)
 public:
  NodeEdge_Edge(Node* p_source, Node* p_dest);
  Node* SourceNode() const;
  Edge* DestEdge() const;
  };

class EdgeNode_Edge : public Edge  // Dendro-dentridic synapse
  {
 protected:
  Edge* mp_source;
  Node* mp_dest;
 public:
  EdgeNode_Edge(Node* p_source, Node* p_dest);
  Edge* SourceEdge() const;
  Node* DestNode() const;
  };

class NodeNode_Edge : public Edge  // Axo-dentritic synapse
  {
 protected:
  Node* mp_source;  // m=membervariable, P=pointer, l=list, i=iterator
  Node* mp_dest;
 public:
  NodeNode_Edge(Node* p_source, Node* p_dest, wgt weight, dey delay);
  Node* SourceNode() const;  // Source=Pre(synaptic)
  Node* DestNode() const;    // Dest(ination)=Post(synaptic)
  };

// ----------------------------------------------------------------------------

class Node  // Neuron: soma
  {
  //pos* mp_pos_x, mp_pos_y, mp_pos_z;
 protected:
  vtg* mp_voltage;
 public:
  Node();
  virtual ~Node()=0;  // =0: pure: Kein eigenständiges Objekt
  void SetVoltage(vtg mp_voltage);
  };

class InputNode : public Node
  {
 protected:
  ObjectCare<Edge>* poplp_destedge;
 public:
  InputNode();
  ~InputNode();
  template <typename D>
  ptr_list<Edge*>::iterator HaveDestEdgeTo(uli count)  // virtual  [C++ Fehler] EDataStructure.h(101): E2462 'virtual' kann nur für Nicht-Template-Elementfunktionen verwendet werden
    {
    return poplp_destedge->HaveElement<D>(count);
    }
  };

class OutputNode : public Node
  {
 protected:
  ptr_list<Edge*>* plp_sourceedge;
  ptr_list<Edge*>::iterator ilp_sourceedge;
 public:
  OutputNode();
  ~OutputNode();
  //virtual ptr_list<Edge*>::iterator HaveSourceEdgeFrom(uli count);
  };

/*class MotorNode : public OutputNode  // test
  {
 public:
  MotorNode();
  ~MotorNode();
  };*/

class InnerNode : public Node  // Bei Mehrfachvererbung und Zusammenführung anscheinend nicht typkompatibel zur Liste mit Zeigern auf den Basisklassentyp.
  {                            // Daher Vererbung von public Node statt von public InputNode, public OutputNode
 protected:                    // und Redundanz von deren Listen und Itteratoren in InnerNode.
  ptr_list<Edge*>* plp_destedge;
  ptr_list<Edge*>::iterator ilp_destedge;
  ptr_list<Edge*>* plp_sourceedge;
  ptr_list<Edge*>::iterator ilp_sourceedge;
 public:
  InnerNode();
  ~InnerNode();
  };

class PyramidalNode : public InnerNode
  {
 public:
  PyramidalNode();
  ~PyramidalNode();
  };

// ----------------------------------------------------------------------------

class Layer
  {
  ptr_list<Node*>::iterator ilp_first;
  ptr_list<Node*>::iterator ilp_node;
  ptr_list<Node*>::iterator ilp_last;
 public:
  //Layer();
  Layer(ptr_list<Node*>::iterator first, ptr_list<Node*>::iterator last);
  //ptr_list<Node*>::iterator GetStart() const;
  ptr_list<Node*>::iterator HaveNode(uli count);
  //ptr_list<Node*>::iterator GetEnd() const;
  //ptr_list<Node*>::iterator SetStart(ptr_list<Node*>::iterator first);
  //ptr_list<Node*>::iterator SetEnd(ptr_list<Node*>::iterator last);
  };

// ----------------------------------------------------------------------------

class Net
  {
  ObjectCare<Node>* poplp_node;
  ptr_list<Layer*>* plp_layer;
  ptr_list<Layer*>::iterator ilp_layer;
 public:
  Net();
  ~Net();
  template <typename D>
  ptr_list<Node*>::iterator HaveNode(uli count)
    {
    return poplp_node->HaveElement<D>(count);
    }
  template <typename D>
  void DefineLayer(uli first, uli last)  // Erstes vor dem letzten Element oder gleich (first<=last)
    {                                                                              if(debug_level>=1)  cout << "Net::DefineLayer(first: " << first << ", last: " << last << ")" << endl;
    plp_layer->push_back(new Layer(HaveNode<D>(first),HaveNode<D>(last)));  // Mit ptr_list error: no matching function for call to 'boost::ptr_list<Layer*>::push_back(Layer*&)'
    }
  };

// ----------------------------------------------------------------------------

class Set
  {
  ObjectCare<Net>* poplp_net;  // poplp(m)=poiter to object containing pointer to list containing pointers (member variable (implyed))
 public:
  Set();
  ~Set();
  template <typename D>                    // Wenn HaveNet=Net Ausdruckssyntaxfehler bei plp_net = new list<Net*>;
  ptr_list<Net*>::iterator HaveNet(usi count)  // Wenn typename D in Funktionsparametern: [C++ Fehler] EDataStructure.cpp(165): E2439 'typename' ist nur in Template-Deklarationen zulässig
    {
    return poplp_net->HaveElement<D>(count);
    }
  };

#endif
