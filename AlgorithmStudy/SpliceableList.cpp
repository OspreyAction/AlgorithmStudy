#include "stdafx.h"
#include "SpliceableList.h"


CSpliceableList::CSpliceableList()
{
    curr = NULL;
    temp = NULL;
    head = NULL;
    tail = NULL;

    elements = 0;
}


CSpliceableList::~CSpliceableList()
{
}


void CSpliceableList::AddNodeAtTail(nodePtr ptr)
{
    curr = head;
    if (curr == NULL)
    {
        head = ptr;
    }
    else
    {
        while (curr != NULL)
        {
            temp = curr;
            curr = curr->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
    tail = ptr;
    elements++;
}

void CSpliceableList::PrintForward()
{
    curr = head;
    while (curr != NULL)
    {
        temp = curr;
        cout << temp->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

void CSpliceableList::PrintBackward()
{
    curr = tail;
    while (curr != NULL)
    {
        temp = curr;
        cout << temp->data << " ";
        curr = curr->prev;
    }
    cout << "\n";
}

void CSpliceableList::DeleteNode(nodePtr ptr)
{
    if (ptr->prev == NULL)
    {
        head = head->next;
        head->prev = NULL;
    }
    else if (ptr->next == NULL)
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
    elements--;
}

void CSpliceableList::RecoverNode(nodePtr ptr)
{
    if (ptr->prev == NULL)
    {
        ptr->next = head;
        head->prev = ptr;
    }
    else if (ptr->next == NULL)
    {
        ptr->prev = tail;
        tail->next = ptr;
    }
    else
    {
        ptr->prev->next = ptr;
        ptr->next->prev = ptr;
    }

    elements++;
}

void CSpliceableList::PrintElements()
{
    cout << elements << " nodes belong to your list\n";
}

