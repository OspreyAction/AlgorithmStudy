#include "stdafx.h"
#include "ListStudy.h"
#include "Node.h"


CListStudy::CListStudy()
{
    head = NULL;
    tail = NULL;
    curr = NULL;
    temp = NULL;

    elements = 0;
}

CListStudy::~CListStudy()
{
}

void CListStudy::AddNode(nodePtr ptr)
{
    if (head != NULL)
    {
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = ptr;
        ptr->prev = curr;
    }
    else
    {
        head = ptr;
    }
    tail = ptr;
    elements++;
}

void CListStudy::DeleteNode(nodePtr ptr)
{
    nodePtr delptr = NULL;
    temp = head;
    curr = head;

    while (curr != NULL && curr->data != ptr->data)
    {
        temp = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        cout << ptr->data << " was not in the list\n";
        delete delptr;
        return;
    }
    else
    {
        delptr = curr;
        if (delptr == head)
        {
            head = head->next;
            head->prev = NULL;
            temp = NULL;
        }
        else if (delptr == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
            temp = NULL;
        }
        else
        {
            curr = curr->next;
            temp->next = curr;
            curr->prev = temp;
        }
        delete delptr;
        cout << "The Value " << ptr->data << " was deleted\n";
    }
    elements--;
}

void CListStudy::PrintList()
{
    curr = head;
    while (curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

void CListStudy::PrintForward()
{
    curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

void CListStudy::PrintBackward()
{
    curr = tail;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << "\n";
}

void CListStudy::PrintElements()
{
    cout << elements << " nodes belong to your list\n";
}