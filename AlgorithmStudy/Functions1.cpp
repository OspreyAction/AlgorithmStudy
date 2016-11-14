
#include "stdafx.h"

bool AbsoluteEqual(double a, double b)
{
    return abs(a - b) < 1e-10;
}

bool RelativeEqual(double a, double b)
{
    return abs(a - b) < 1e-8 * fmax(abs(a), abs(b));
}

bool IsEqual(double a, double b)
{
    double diff = abs(a - b);

    if (diff < 1e-10) return true;
    
    return diff < 1e-8 * fmax(abs(a), abs(b));

}

int majority1(const vector<int>& a)
{
    int N = a.size();

    int majority = -1, majorityCount = 0;

    for (int i = 0; i < N; i++)
    {
        int V = a[i], count = 0;
        for (int j = 0; j < N; j++)
        {
            if (a[j] == V) count++;
        }

        if (count > majorityCount)
        {
            majorityCount = count;
            majority = V;
        }
    }

    return majority;
}

int majority2(const vector<int>& a)
{
    int N = a.size();

    vector<int> count(101, 0);

    for (int i = 0; i < N; i++)
    {
        count[a[i]]++;
    }

    int majority = 0;
    
    for (int j = 0; j < 100; j++)
    {
        if (count[j] > count[majority])
        {
            majority = j;
        }
    }

    return majority;
}

