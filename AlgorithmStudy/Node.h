#pragma once

typedef struct node
{
    int data;
    node* next;
    node* prev;
}* nodePtr;

int GetData(nodePtr node);

void SetNode(nodePtr node, int data);
nodePtr CreateNode(int data);
