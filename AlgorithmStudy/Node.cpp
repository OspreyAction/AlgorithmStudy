#include "stdafx.h"
#include "Node.h"

nodePtr CreateNode(int data)
{
    nodePtr n = new node;
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void SetNode(nodePtr node, int data)
{
    node->data = data;
}

int GetData(nodePtr node)
{
    int data = node->data;
    return data;
}
