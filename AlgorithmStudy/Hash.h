#pragma once
class CHash
{
public:
    CHash();
    ~CHash();

public:
    int Hash(string key);
    void AddItem(string name, string drink);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    void FindDrink(string name);
    void RemoveItem(string name);


private:
    static const int nTableSize = 10;

    struct item
    {
        string name;
        string drink;
        item* next;
    };

    item* HashTable[nTableSize];
};

