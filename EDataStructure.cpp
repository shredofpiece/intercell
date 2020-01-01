#include "EDataStructure.h"

// ============================================================================

Edge::Edge(wgt weight, dey delay):mp_weight(new wgt(weight)), mp_delay(new dey(delay))
  {
  /*mp_weight = new wgt;  // anlegen
  mp_delay = new dey;
  *mp_weight = weight;  // füllen
  *mp_delay = delay;*/                                                           if(debug_level>=5)  cout << "Edge::Edge(weight: " << *mp_weight << ", delay: " << *mp_delay << ")\tKonstruktor" << endl;
  }

Edge::~Edge()
  {
  }

wgt Edge::GetWeight() const
  {                                                                              if(debug_level>=1)  cout << "weight: " << *mp_weight << "NodeNode_Edge::GetWeight()" << endl;
  return *mp_weight;
  }

dey Edge::GetDelay() const
  {                                                                              if(debug_level>=1)  cout << "delay: " << *mp_delay << "NodeNode_Edge::GetDelay()" << endl;
  return *mp_delay;
  }

// ----------------------------------------------------------------------------

NodeNode_Edge::NodeNode_Edge(Node* p_source, Node* p_dest, wgt weight, dey delay):Edge(weight,delay), mp_source(p_source), mp_dest(p_dest)
  {
  mp_source = p_source;
  mp_dest = p_dest;                                                              if(debug_level>=5)  cout << "NodeNode_Edge::NodeNode_Edge(psource, p_dest)\tKonstruktor" << endl;
  }

Node* NodeNode_Edge::SourceNode() const
  {                                                                              if(debug_level>=6)  cout << "NodeNode_Edge::SourceNode()\tQuellneuronadresse: " << mp_source << endl;
  return mp_source;
  }

Node* NodeNode_Edge::DestNode() const
  {                                                                              if(debug_level>=6)  cout << "NodeNode_Edge::DestNode()\tZielneuronadresse: " << mp_dest << endl;
  return mp_dest;
  }

// ============================================================================

Node::Node()
  {
  mp_voltage = new vtg;
  SetVoltage(-0.7);                                                              if(debug_level>=5)  cout << "Node::Node()\tKonstruktor" << endl;
  }

Node::~Node()
  {
  delete mp_voltage;                                                             if(debug_level>=5)  cout << "Node::~Node()\tDestruktor" << endl;
  }

void Node::SetVoltage(vtg voltage)
  {
  *mp_voltage=voltage;                                                           if(debug_level>=1)  cout << "Node::SetVoltage(voltage: " << *mp_voltage << ")" << endl;
  }

// ----------------------------------------------------------------------------

InputNode::InputNode()  // Sensory neuron
  {                                                                              if(debug_level>=5)  cout << "InputNode::InputNode()\tKonstruktor" << endl;
  poplp_destedge = new ObjectCare<Edge>;
  }

InputNode::~InputNode()
  {                                                                              if(debug_level>=5)  cout << "InputNode::~InputNode()\tDestruktor" << endl;
  delete poplp_destedge;
  }

// ----------------------------------------------------------------------------

OutputNode::OutputNode()  // Motor neuron, Secretatory neuron
  {                                                                              if(debug_level>=5)  cout << "OutputNode::OutputNode()\tKonstruktor" << endl;
  plp_sourceedge = new ptr_list<Edge*>;
  }

OutputNode::~OutputNode()
  {                                                                              if(debug_level>=5)  cout << "OutputNode::~OutputNode()\tDestruktor" << endl;
  delete plp_sourceedge;
  }

//ptr_list<Edge*>::iterator OutputNode::HaveSourceEdgeFrom(uli count)
//  {
//  }

// ----------------------------------------------------------------------------
/*
MotorNode::MotorNode()
  {                                                                              if(debug_level>=5)  cout << "MotorNode::MotorNode()\tKonstruktor" << endl;
  }

MotorNode::~MotorNode()
  {                                                                              if(debug_level>=5)  cout << "MotorNode::~MotorNode()\tDestruktor" << endl;
  }
*/
// ----------------------------------------------------------------------------

InnerNode::InnerNode()
  {                                                                              if(debug_level>=5)  cout << "InnerNode::InnerNode()\tKonstruktor" << endl;
  plp_sourceedge = new ptr_list<Edge*>;
  plp_destedge   = new ptr_list<Edge*>;
  }

InnerNode::~InnerNode()
  {                                                                              if(debug_level>=5)  cout << "InnerNode::~InnerNode()\tDestruktor" << endl;
  delete plp_sourceedge;
  delete plp_destedge;
  }

// ----------------------------------------------------------------------------

PyramidalNode::PyramidalNode()
  {                                                                              if(debug_level>=5)  cout << "PyramidalNode::PyramidalNode()\tKonstruktor" << endl;
  }

PyramidalNode::~PyramidalNode()
  {                                                                              if(debug_level>=5)  cout << "PyramidalNode::~PyramidalNode()\tDestruktor" << endl;
  }

// ============================================================================

Layer::Layer(ptr_list<Node*>::iterator first, ptr_list<Node*>::iterator last):ilp_first(first), ilp_last(last)
  {
  }

ptr_list<Node*>::iterator Layer::HaveNode(uli count)  // count bezeichnet Nummer des Listenelements (1 >= count >= letztes Element)
  {                                                                              if(debug_level>=2)  cout << "HaveNode(count: " << count << ")" << endl;
  ilp_node=ilp_first;  // Iterator initialisieren
  --count;
  do
    {
    ++ilp_node;        // Countschritt bearbeitet
    --count;
    }
  while (count>0);     // Bis count bearbeitet
  return ilp_node;
  }

// ============================================================================

Net::Net()
  {
  poplp_node = new ObjectCare<Node>;
  plp_layer = new ptr_list<Layer*>;                                                  if(debug_level>=5)  cout << "Net::Net()\tKonstruktor" << endl;
  }

Net::~Net()
  {                                                                              if(debug_level>=5)  cout << "Net::~Net()\tDestruktor" << endl;
  delete poplp_node;
  //DeleteListAndTheirElements<Layer>(plp_layer, ilp_layer);
  delete plp_layer;
  }

// ============================================================================

Set::Set()
  {                                                                              if(debug_level>=5)  cout << "Set::Set()\tKonstruktor" << endl;
  poplp_net = new ObjectCare<Net>;
  }

Set::~Set()
  {                                                                              if(debug_level>=5)  cout << "Set::~Set()\tDestruktor" << endl;
  delete poplp_net;
  }
