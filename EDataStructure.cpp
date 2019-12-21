#include "EDataStructure.h"

// ============================================================================

Edge::Edge(wgt weight, dey delay):mp_weight(new wgt(weight)), mp_delay(new dey(delay))
  {
  }

Edge::~Edge()
  {
  }

wgt Edge::GetWeight() const
  {
  return *mp_weight;
  }

dey Edge::GetDelay() const
  {
  return *mp_delay;
  }

// ----------------------------------------------------------------------------

NodeNode_Edge::NodeNode_Edge(Node* p_source, Node* p_dest, wgt weight, dey delay):Edge(weight,delay), mp_source(p_source), mp_dest(p_dest)
  {
  mp_source = p_source;
  mp_dest = p_dest;
  }

Node* NodeNode_Edge::SourceNode() const
  {
  return mp_source;
  }

Node* NodeNode_Edge::DestNode() const
  {
  return mp_dest;
  }

// ============================================================================

Node::Node()
  {
  mp_voltage = new vtg;
  SetVoltage(-0.7);
  }

Node::~Node()
  {
  delete mp_voltage;
  }

void Node::SetVoltage(vtg voltage)
  {
  *mp_voltage=voltage;
  }

// ----------------------------------------------------------------------------

InputNode::InputNode()  // Sensory neuron
  {
  poplp_destedge = new ObjectCare<Edge>;
  }

InputNode::~InputNode()
  {
  delete poplp_destedge;
  }

// ----------------------------------------------------------------------------

OutputNode::OutputNode()  // Motor neuron, Secretatory neuron
  {
  plp_sourceedge = new list<Edge*>;
  }

OutputNode::~OutputNode()
  {
  delete plp_sourceedge;
  }

//list<Edge*>::iterator OutputNode::HaveSourceEdgeFrom(uli count)
//  {
//  }

// ----------------------------------------------------------------------------
/*
MotorNode::MotorNode()
  {
  }

MotorNode::~MotorNode()
  {
  }
*/
// ----------------------------------------------------------------------------

InnerNode::InnerNode()
  {
  plp_sourceedge = new list<Edge*>;
  plp_destedge   = new list<Edge*>;
  }

InnerNode::~InnerNode()
  {
  delete plp_sourceedge;
  delete plp_destedge;
  }

// ----------------------------------------------------------------------------

PyramidalNode::PyramidalNode()
  {
  }

PyramidalNode::~PyramidalNode()
  {
  }

// ============================================================================

Layer::Layer(list<Node*>::iterator first, list<Node*>::iterator last):ilp_first(first), ilp_last(last)
  {
  }

list<Node*>::iterator Layer::HaveNode(uli count)  // count bezeichnet Nummer des Listenelements (1 >= count >= letztes Element)
  {
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
  plp_layer = new list<Layer*>;
  }

Net::~Net()
  {
  delete poplp_node;
  DeleteListAndTheirElements<Layer>(plp_layer, ilp_layer);
  }

// ============================================================================

Set::Set()
  {
  poplp_net = new ObjectCare<Net>;
  }

Set::~Set()
  {
  delete poplp_net;
  }
