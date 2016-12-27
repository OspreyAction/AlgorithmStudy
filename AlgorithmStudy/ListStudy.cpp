#include "stdafx.h"
#include "ListStudy.h"

using namespace std;

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

void CListStudy::AddNode(int addData)
{
    nodePtr n = new node;
    n->next = NULL;
    n->prev = NULL;
    n->data = addData;

    if (head != NULL)
    {
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
        n->prev = curr;
    }
    else
    {
        head = n;
    }
    tail = n;
    elements++;
}

void CListStudy::DeleteNode(int delData)
{
    nodePtr delptr = NULL;
    temp = head;
    curr = head;

    while (curr != NULL && curr->data != delData)
    {
        temp = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        cout << delData << " was not in the list\n";
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
        cout << "The Value " << delData << " was deleted\n";
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