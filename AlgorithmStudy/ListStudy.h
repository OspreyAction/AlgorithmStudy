#include "Node.h"

#pragma once
class CListStudy
{
public:
    CListStudy();
    ~CListStudy();

//private:
public:
    nodePtr head;
    nodePtr tail;
    nodePtr curr;
    nodePtr temp;

    int elements;

public:
    void AddNode(nodePtr ptr);
    void DeleteNode(nodePtr ptr);
    void PrintList();
    void PrintForward();
    void PrintBackward();
    void PrintElements();
};

