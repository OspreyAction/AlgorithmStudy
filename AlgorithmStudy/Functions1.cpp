
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

unsigned int Translate(unsigned int input)
{

    int* c = new int[32];
    unsigned int d = input;
    unsigned int output = 0;
    for (int j = 0; j < 32; j++)
    {
        int p = 31 - j;
        if (d < (unsigned int)pow(2, p))
        {
            c[j] = 0;
        }
        else
        {
            c[j] = 1;
            d = d - (unsigned int)pow(2, p);
        }
    }

    for (int k = 0; k < 4; k++)
    {
        for (int l = 1; l < 9; l++)
        {
            int q = k * 8 + l - 1;
            int r = 31 - q;
            int s = 3 - k;
            if (c[r] == 1)
            {
                output = output + (unsigned int)pow(2, (s * 8 + l - 1));
            }
        }
    }
    return output;
}

int SquareXorY(int* a)
{
    int out;
    if (a[1] == a[0])
    {
        out = a[2];
    }
    else
    {
        if (a[2] == a[1])
        {
            out = a[0];
        }
        else
        {
            out = a[1];
        }
    }
    return out;
}

char* Translate2(char* input)
{
    vector<char> first;
    vector<char> second;
    int size;
    char* out = new char[1001];
    int R = 0;
    while (input[R] != '\0')
    {
        first.push_back(input[R]);
        second.push_back(input[R + 1]);
        R += 2;
    }
    size = first.size();
    int* order = new int[size];
    int* sorted = new int[size];
    int* indices = new int[size];
    for (int j = 0; j < size; j++)
    {
        order[j] = (int)first[j] * 999 + (int)second[j];
        sorted[j] = (int)first[j] * 999 + (int)second[j];
    }
    sort(sorted, sorted + size);
    int h;
    for (int k = 0; k < size; k++)
    {
        h = sorted[k];
        for (int l = 0; l < size; l++)
        {
            if (h == order[l])
            {
                indices[k] = l;
            }
        }
    }
    int IP = 0;
    for (int m = 0; m < size; m++)
    {
        out[IP] = first[indices[m]];
        out[IP + 1] = second[indices[m]];
        IP += 2;
    }
    return out;
}

vector<char> Translate3(char* input)
{
    vector<char> odd;
    vector<char> even;
    vector<char> out;
    int j = 0;
    while (input[j] != '\0')
    {
        odd.push_back(input[j]);
        if (input[j + 1] != '\0')
        {
            even.push_back(input[j + 1]);
        }
        j += 2;
    }
    int sizeodd = odd.size();
    int sizeeven = even.size();
    for (int j = 0; j < sizeodd; j++)
    {
        out.push_back(odd[j]);
    }
    for (int k = 0; k < sizeeven; k++)
    {
        out.push_back(even[k]);
    }
    return out;
}

vector<char> extract(char* input, int target)
{
    vector<char> out;
    int i = 0;
    while (input[i] != '\0')
    {
        if (i != target - 1)
        {
            out.push_back(input[i]);
        }
        i++;
    }
    return out;
}