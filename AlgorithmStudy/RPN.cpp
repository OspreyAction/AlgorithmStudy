#include "stdafx.h"
#include "RPN.h"


CRPN::CRPN()
{
}


CRPN::~CRPN()
{
}


bool CRPN::isOperator(const string& input)
{
    string ops[] = {"-", "+", "*", "/"};

    for (int i = 0; i < 4; i++)
    {
        if (input == ops[i])
        {
            return true;
        }
    }

    return false;
}

void CRPN::performOp(const string& input)
{
    double lVal = 0.0;
    double rVal = 0.0;
    double result = 0.0;

    rVal = calcStack.top();
    calcStack.pop();

    lVal = calcStack.top();
    calcStack.pop();

    if (input == "-")
    {
        result = lVal - rVal;
    }
    else if (input == "+")
    {
        result = lVal + rVal;
    }
    else if (input == "*")
    {
        result = lVal * rVal;
    }
    else
    {
        result = lVal / rVal;
    }

    cout << result << endl;
}

void CRPN::Calculator()
{
    string input;

    while (true)
    {
        // display prompt
        cout << ">>";

        // get input
        cin >> input;

        // check for numeric value
        double num = 0.0;
        if (istringstream(input) >> num)
        {
            calcStack.push(num);
        }

        // check for operator
        else if (isOperator(input))
        {
            performOp(input);
        }

        // check for quit
        else if (input == "q")
        {
            return;
        }

        // invalid output
        else
        {
            cout << "Invalid input" << endl;
        }
    }
}