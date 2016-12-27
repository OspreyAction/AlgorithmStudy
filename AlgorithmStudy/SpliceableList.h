#include "Node.h"

#pragma once
class CSpliceableList
{
public:
    CSpliceableList();
    ~CSpliceableList();

//private:
public:
    nodePtr curr;
    nodePtr temp;
    nodePtr head;
    nodePtr tail;

    int elements;

public:
    void PrintForward();
    void PrintBackward();
    void AddNodeAtTail(nodePtr ptr);
    void DeleteNode(nodePtr ptr);
    void RecoverNode(nodePtr ptr);

};

