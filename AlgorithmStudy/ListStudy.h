#pragma once
class CListStudy
{
public:
    CListStudy();
    ~CListStudy();

private:

    typedef struct node
    {
        int data;
        node* next;
        node* prev;
    }* nodePtr;

    nodePtr head;
    nodePtr tail;
    nodePtr curr;
    nodePtr temp;

    int elements;

public:
    void AddNode(int addData);
    void DeleteNode(int delData);
    void PrintList();
    void PrintForward();
    void PrintBackward();
    void PrintElements();
};

