run [debug level]

Skeleton of a neural netork
###########################


This code was intended to model intercell communication
starting with brain cells resembling a neural network.
It is written in C++11 using debian linux.

close to the physical level.


Class diagram
=============

        -Layer-  --Hormon--
       n|     X1 |n      1O
        |     |  |        | ----------
       1X     |n O1      n| X0..1   1|
SetX---NetX---NodeX------Edge---------
   1  n   1  n    1  1..2   |
              (Position)    |
 (MotorNode)  Voltage       |
      O       O  O          |
      |       |  |          |
     OutputNode  InputNode  |O-----NodeEdge_Edge
              O  O          |
              |  |          |
           InnerNode        |O-----EdgeNode_Edge
               O            |
               |            |
         PyramidalNode      |O-----NodeNode_Edge

Classes without relationships:
ObjectCare, DeleteListAndTheirElements

X -> aggregation(?) (resembles filled arrowtiptriangle)
O -> komposition(?) (resembles blank arrowtiptriangle)


File structure
==============

NN.cpp                          where the calls are
NN.h                            includes *.h
EDataStructure.cpp              (like it's brain), ^classes having relationships
EDataStructure.h                +workaround (ObjectCare)
EDatatype.h                     typedefs, ranges, (counting from 1 instead of 0)
EDebug.h                        deklaring integer debug_level
TDeleteListAndTheirElements.h   freeing memory
run                             executable after building
doc/bad.txt                     errors
doc/readme.txt                  this
log/.                           console output


What it does
============

Calls in main lead to the ->creation of objects, belonging to the network structure<-.
Likewise they are destructed after pressing [ENTER] for leaving the program.
In between there is no action yet. The log goes to standard output.


Debug level
===========

0   quiet
1   default: variables
2   creations
5   konstruction/destruction
6   memory adresses


Abbreviations
=============

Filenames
V   Variable
F   Function
E   Element (Class)
T   Template

Variables
mp          (m)ember variable holding a (p)ointer
plp         (p)ointer to (l)ist holding (p)ointers
ilp         (i)terator of (l)ist holding (p)ointers
poplp(m)    (p)oiter to (o)bject holding (p)ointer to (l)ist holding (p)ointers ((m)ember variable (implyed))

Templates
D           Data (type of pointer in list)
C           Count
B           Base class => Basisklasse

Logging
ObjC        (Obj)ect(C)are
HavEl       (Hav)e(El)ement
DelLstEl    (Del)ete(L)i(st)AndTheir(El)ements


Explainations
=============

Have
Get / Make and Get if not existing


SourceEdgeFrom


From/To is a Node or an Edge. The later regarding Advanced Connectivity.

Node                           Node
(/Edge)  Edge   Node  Edge  (/Edge)
From-------------<o>-------------To
        Source        Dest



Connectivity
------------


Axo-dentritic synapse
'''''''''''''''''''''

<o>----|---------<o>
   NodeNode_Edge


Axo-axonic synapse
''''''''''''''''''

<o>---------|----<o>   (axons drawn longer than dentrides)
              |
              | <- NodeEdge_Edge
              |
<o>---------|----<o>
Connection of a Node to an Etge

The firing of the source neuron has a temporary influence
(increase, also decrease?) on the weight of the destination edge (ShortTimePotentiation).


Dendro-dentridic synapse
''''''''''''''''''''''''

<o>----|---------<o>
     |
     | <---------- EdgeNode_Edge
     |
<o>----|---------<o>
Conection of an Etch to a Node






Layers can not be handled by ObjectCare because..
..(structure: first, last, actual element ?)..


Information Source
------------------

Neuroscience
Clarke Neurology 2009

Coding
Richard Kaiser - C++ mit dem Borland C++ Builder
Strager
