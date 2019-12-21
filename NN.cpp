#include "NN.h"

int main(int argc, char* argv[])
  {
  Set* p_set = new Set;  // Add set
  // Example network:  Input:      Hidden:      Output:
  //                    (1)          (3)
  //                    (2)          (4)          (6)
  //                                 (5)          (7)
  (*(p_set->HaveNet<Net>(1)))->HaveNode<InputNode>(2);
  (*(p_set->HaveNet<Net>(1)))->HaveNode<PyramidalNode>(5);
  (*(p_set->HaveNet<Net>(1)))->HaveNode<OutputNode>(7);

  // Schichten:
  (*(p_set->HaveNet<Net>(1)))->DefineLayer<InputNode>(1,2);
  (*(p_set->HaveNet<Net>(1)))->DefineLayer<PyramidalNode>(3,5);
  (*(p_set->HaveNet<Net>(1)))->DefineLayer<OutputNode>(6,7);

  // Gewünschtere Zugriffsart:
  // Instance->Net(1)->Node(1)->ToNode(3)->weight += 1;  // typedef ?
  // Instance->Net(1)->Node(4)->ToAxonBetweenNode(5,7)->weight -= 1;
  // Instance->Net(1)->Node(5)->FromDentrideBetweenNode(2,4)->weight += 1;

  cin.get();  // Dummyinput for preventing the console window
              // from beeing closed automatically in some environments.
  delete p_set;
  return 0;
  }
