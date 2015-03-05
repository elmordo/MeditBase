Graphs
======

Nodes
-----

Nodes are represented by Node class. Instance of this class hold references to parent and child nodes. This reference is realized as pointer.
Nodes can hold some data. These data is stored as void* pointer and when node is destroyed, data is not destroyed. It has to be deallocated manualy (it can be used somewhere deep in application and deallocation can lead to application crash).

Graph representation
--------------------

