#ifndef DataStructureH
#define DataStructureH

#include <iostream>         // cout
#include <list>
#include <typeinfo>         // typeid
//#include <type_traits>    // is_baseof
//#include <boost/ptr_container/ptr_list.hpp>  // newer version of C++? innerhalb boost: [C++ Fehler] remove_cv.hpp(22): E2238 Bezeichner 'remove_cv<T>' mehrfach deklariert
#include "DeleteListAndTheirElements.h"
#include "Datatype.h"
//#include "Time.h"
#include "Debug.h"         // debug_level
using std::list;
using std::cout;
using std::endl;
//using boost::ptr_list;

// ----------------------------------------------------------------------------

template <typename B>  // B=Basis(klasse), D=Data, C=Count
class ObjectCare       // ListAndIteratorObjectCare
  {
  list<B*>* plp;
  typename list<B*>::iterator ilp;
 public:
  ObjectCare()
    {                                                                            if(debug_level>=5)  cout << "ObjectCare::ObjectCare()\tKonstruktor" << endl;
    plp = new list<B*>;
    }
  ~ObjectCare()
    {                                                                            if(debug_level>=5)  cout << "ObjectCare::~ObjectCare()\tDestruktor" << endl;
    DeleteListAndTheirElements<B>(plp,ilp);  // Mit g++ not declared in this scope, wenn dieser Header in TDeleteListAndTheirElements.h inkludiert
    }
  template <typename D/*, typename... Args*/>  // D=Data (Type of pointer in list), C=count
  void AddElement(/*Args... args*/)
    {
    plp->push_back(new D/*(args...)*/);                                                       // [C++ Warnung] EDataStructure.h(20): W8030 Temporäre Größe für Parameter '__x' in Aufruf von 'list<Node *,allocator<Node *> >::push_back(Node * const &)' verwendet
    }
  template <typename D, typename C/*, typename... Args*/>  // D=Data (Type of pointer in list), C=count,  // A=Arguments (for Constructor)
  typename list<B*>::iterator HaveElement(C count/*, Args... args*/)
    {                                                                            if(debug_level>=1)  cout << "ObjC::HavEl(" << +count << ". Typ: " << typeid(D).name() << ")" << endl << "ObjC::HavEl(" << +count << ". Typ: " << typeid(D).name() << ")\tAnfangsobjektanzahl: " << plp->size() << endl;
    while(plp->size()<count)  // Solange Basisgröße kleiner Auswahl              // Wenn Mehrfachvererbung und zusammenführung InnerNode->InputNode, OutputNode->Node anscheinend keine Typkompatibilität von InnerNode zur Liste mit Zeigern auf die Basisklasse Node:
      AddElement<D/*,Args...*/>(/*args...*/);        // Füge Element hinzu
    ilp=plp->begin();         /* Itterator inititialisieren   */                 if(debug_level>=6)  cout << "ObjC::HavEl(" << +count << ". Typ: " << typeid(D).name() << ")\tilp = plp->begin(): " << *ilp << endl;
    advance(ilp, count-1);    /* Auf Auswahl Zeigen           */                 if(debug_level>=1)  cout << "ObjC::HavEl(" << +count << ". Typ: " << typeid(D).name() << ")\tEndobjektanzahl: " << plp->size() << endl;  if(debug_level>=6)  cout << "ObjC::HavEl(" << +count << ". Typ: " << typeid(D).name() << ")\tAdr. 1.\tObjekt: " << *(plp->begin()) << endl << "ObjC::HavEl(" << +count << ". Typ: " << typeid(D).name() << ")\tAdr. " << +count << ".\tObjekt: " << *ilp << " (Rueckgabe)" << endl;
    return ilp;               // Zeig auf Auswahl zurückgeben
    }
  };

// ----------------------------------------------------------------------------

class Node;  // Vorwärtsdeklaration

//class Hormon // (Neuro)hormone distribution  // parakrin, neuroendokrin (z.B chemisches rufen nach axonalen synapsen)

class Edge  // Synaptic gap, synapses (weight), axon, dentride
  {
 protected:
  wgt* mp_weight;
  dey* mp_delay;
 public:
  Edge(wgt weight=0.0, dey delay=0.0);
  virtual ~Edge()=0;  // =0: pure: Kein eigenständiges Objekt
  wgt GetWeight() const;
  dey GetDelay() const;
  // inhibiting tendency (max inhibiting)
  // inhibiting speed
  // recovery speed // expo curve
  //path
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
  Node* mp_source;
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

class InputNode
  {
 protected:
  ObjectCare<Edge>* poplp_destedge;
 public:
  InputNode();
  virtual ~InputNode()=0;  // =0: pure: Kein eigenständiges Objekt
  template <typename D>  // datatype of count depends on D -> taking biggest till better solutuion see also datatype.h
  list<Edge*>::iterator HaveDestEdgeTo(cnoe count)  // virtual  [C++ Fehler] EDataStructure.h(101): E2462 'virtual' kann nur für Nicht-Template-Elementfunktionen verwendet werden
    {
    return poplp_destedge->HaveElement<D>(count);
    }
  };

class OutputNode
  {
 protected:
  ObjectCare<Edge>* poplp_sourceedge;
 public:
  OutputNode();
  virtual ~OutputNode()=0;  // =0: pure: Kein eigenständiges Objekt
  //virtual list<Edge*>::iterator HaveSourceEdgeFrom(cnoe count);
  template <typename D>  // datatype of count depends on D  see above (InputNode)
  list<Edge*>::iterator HaveSourceEdgeFrom(cnoe count)  // virtual -> E2462  see above (InputNode)
    {
    return poplp_sourceedge->HaveElement<D>(count);
    }
  };

class ReceptorNode : public Node, public InputNode
  {
 public:
  ReceptorNode();
  ~ReceptorNode();
  };

class ActorNode : public Node, public OutputNode
  {
 public:
  ActorNode();
  ~ActorNode();
  };

class InnerNode : public InputNode, public OutputNode
  {
 public:
  InnerNode();
  ~InnerNode()=0;  // =0: pure: Kein eigenständiges Objekt  // virtual is inherrited
  };

class PyramidalNode : public Node, public InnerNode
  {
 public:
  PyramidalNode();
  ~PyramidalNode();
  };

class MotorNode : public Node, public InnerNode
  {
 public:
  MotorNode();
  ~MotorNode();
  };

// ----------------------------------------------------------------------------

class Layer
  {
  ObjectCare<Node>* poplp_node;  // poplp(m)=poiter to object containing pointer to list containing pointers (member variable (implyed))
 public:
  Layer();
  ~Layer();
  template <typename D>                    // Wenn HaveNet=Net Ausdruckssyntaxfehler bei plp_net = new list<Net*>;
  list<Node*>::iterator HaveNode(cnde count)  // Wenn typename D in Funktionsparametern: [C++ Fehler] EDataStructure.cpp(165): E2439 'typename' ist nur in Template-Deklarationen zulässig
    {
    return poplp_node->HaveElement<D>(count);
    }
  };

// ----------------------------------------------------------------------------

class Span
  {
  list<Node*>::iterator ilp_first;
  list<Node*>::iterator ilp_node;
  list<Node*>::iterator ilp_last;
 public:
  //Span();
  Span(list<Node*>::iterator first, list<Node*>::iterator last);
  //list<Node*>::iterator GetStart() const;
  list<Node*>::iterator HaveNode(cnde count);
  //list<Node*>::iterator GetEnd() const;
  //list<Node*>::iterator SetStart(list<Node*>::iterator first);
  //list<Node*>::iterator SetEnd(list<Node*>::iterator last);
  };

// ----------------------------------------------------------------------------

class Net
  {
  ObjectCare<Node>* poplp_node;
  ObjectCare<Layer>* poplp_layer;
  list<Span*>* plp_span;
  list<Span*>::iterator ilp_span;
 public:
  Net();
  ~Net();
  template <typename D>
  list<Node*>::iterator HaveNode(cnde count)
    {
    return poplp_node->HaveElement<D>(count);
    }
  template <typename D>
  list<Layer*>::iterator HaveLayer(clay count)
    {
    return poplp_layer->HaveElement<D>(count);
    }
  template <typename D>
  void DefineSpan(cnde first, cnde last)  // Erstes vor dem letzten Element oder gleich (first<=last)
    {                                                                              if(debug_level>=1)  cout << "Net::DefineSpan(first: " << first << ", last: " << last << ")" << endl;
    plp_span->push_back(new Span(HaveNode<D>(first),HaveNode<D>(last)));  // boost ptr_list not having push_back  // Mit ptr_list error: no matching function for call to 'boost::ptr_list<Span*>::push_back(Span*&)'
    //plp_span->push_back(new Span(HaveElement<D>(first),HaveElement<D>(last)));  // boost ptr_list not having push_back  // Mit ptr_list error: no matching function for call to 'boost::ptr_list<Span*>::push_back(Span*&)'
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
  list<Net*>::iterator HaveNet(cnet count)  // Wenn typename D in Funktionsparametern: [C++ Fehler] EDataStructure.cpp(165): E2439 'typename' ist nur in Template-Deklarationen zulässig
    {
    return poplp_net->HaveElement<D>(count);
    }
  };

#endif
