Skeleton of a neural netork
###########################


This code was intended to model intercell communication
starting with brain cells resembling a neural network.
It is written in C++11 using debian linux.


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
         PyramidalNode      |O-----NodeEdge_Edge

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
run                             executable for debian
readme_en.txt                   this

Double deklaration of debug_level (NN.h, EDebug.h). Other errors regarding debug level ?


What it does
============

Calls in main lead to the ->creation of objects, belonging to the network structure<-.
Likewise they are destroyed after hitting [ENTER] for leaving the program.
In between there is nothing else implemented yet. The log goes to standard output.

