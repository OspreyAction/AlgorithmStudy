
#include "stdafx.h"

#pragma warning (disable : 4996)

int _tmain(int argc, _TCHAR* argv[])
{
    CHash HashObject;
    string name = "";

    HashObject.AddItem("Paul", "Locha");
    HashObject.AddItem("Kim", "Iced Mocha");
    HashObject.AddItem("Emma", "Strawberry Smoothy");
    HashObject.AddItem("Annie", "Hot Chocolate");
    HashObject.AddItem("Sarah", "Passion Tea");
    HashObject.AddItem("Pepper", "Caramel Mocha");
    HashObject.AddItem("Mike", "Chai Tea");
    HashObject.AddItem("Steve", "Apple Cider");
    HashObject.AddItem("Bill", "Root Beer");
    HashObject.AddItem("Marie", "Skinny Latte");
    HashObject.AddItem("Susan", "Water");
    HashObject.AddItem("Joe", "Green Tea");

    HashObject.PrintItemsInIndex(2);

    while (name != "exit")
    {
        cout << "Remove ";
        cin >> name;
        if (name != "exit")
        {
            HashObject.RemoveItem(name);
        }
    }

    HashObject.PrintItemsInIndex(2);

    //HashObject.PrintItemsInIndex(8);

    return 0;
}

