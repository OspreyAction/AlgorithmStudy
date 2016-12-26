#include "stdafx.h"
#include "Hash.h"

CHash::CHash()
{
    for (int i = 0; i < nTableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
    }
}


CHash::~CHash()
{
}

void CHash::AddItem(string name, string drink)
{
    int index = Hash(name);

    if (HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
        item* ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

int CHash::NumberOfItemsInIndex(int index)
{
    int count = 0;

    if (HashTable[index]->name == "empty")
    {
        return count;
    }
    else
    {
        count++;
        item* ptr = HashTable[index];
        while (ptr->next != NULL)
        {
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

void CHash::PrintTable()
{
    int number = 0;

    for (int i = 0; i < nTableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        cout << "------------------------\n";
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink << endl;
        cout << "# of items = " << number << endl;
        cout << "------------------------\n";
    }
}

void CHash::PrintItemsInIndex(int index)
{
    item* ptr = HashTable[index];

    if (ptr->name == "empty")
    {
        cout << "index = " << index << " is empty\n";
    }
    else
    {
        cout << "index " << index << " contains the following item\n";
        while (ptr != NULL)
        {
            cout << "------------------------\n";
            cout << ptr->name << endl;
            cout << ptr->drink << endl;
            cout << "------------------------\n";
            ptr = ptr->next;
        }
    }
}

int CHash::Hash(string key)
{
    int hash = 0;
    int index = 0;

    for (int i = 0; i < key.length(); i++)
    {
        hash = (hash + (int)key[i]) * 17;
    }

    index = hash % nTableSize;

    return index;
}

void CHash::FindDrink(string name)
{
    int index = Hash(name);
    bool foundName = false;
    string drink;

    item* ptr = HashTable[index];
    while (ptr != NULL)
    {
        if (ptr->name == name)
        {
            foundName = true;
            drink = ptr->drink;
        }
        ptr = ptr->next;
    }
    if (foundName == true)
    {
        cout << "Favorite drink = " << drink << endl;
    }
    else
    {
        cout << name << "'s info was found in the Hash Table\n";
    }
}

void CHash::RemoveItem(string name)
{
    int index = Hash(name);

    item* delptr;
    item* p1;
    item* p2;

    // Case 0 - bucket is empty
    if (HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
    {
        cout << name << "was not found in the Hash Table\n";
    }

    // Case 1 - only 1 item contained in bucket and that item has matching name
    else if (HashTable[index]->name == name && HashTable[index]->next == NULL)
    {
        HashTable[index]->name = "empty";
        HashTable[index]->drink = "empty";
        cout << name << " was removed from the Hash Table\n";
    }

    // Case 2 - match is located in the first item in the bucket but there are more items in the bucket
    else if (HashTable[index]->name == name)
    {
        delptr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delptr;
        cout << name << " was removed from the Hash Table\n";
    }

    // Case 3 - bucket contains items but first item is not a match
    else
    {
        p1 = HashTable[index]->next;
        p2 = HashTable[index];

        while (p1 != NULL && p1->name != name)
        {
            p2 = p1;
            p1 = p1->next;

        }
        // Case 3.1 - no match
        if (p1 == NULL)
        {
            cout << name << "was not found in the Hash Table\n";
        }
        // Case 3.2 - match is found
        else
        {
            delptr = p1;
            p1 = p1->next;
            p2->next = p1;

            delete delptr;
            cout << name << " was removed from the Hash Table\n";
        }
    }

}
