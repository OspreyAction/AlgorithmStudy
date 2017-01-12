
#include "stdafx.h"

#pragma warning (disable : 4996)

int _tmain(int argc, _TCHAR* argv[])
{

    stack<int> myStack;

    myStack.push(5);
    myStack.push(3);
    myStack.push(2);

    cout << "Number of ints on the stack : " << myStack.size() << endl;

    while (!myStack.empty())
    {
        cout << "popping " << myStack.top() << endl;
        myStack.pop();
    }

    CRPN rpn;

    //MyJosephus(40, 3);

}
