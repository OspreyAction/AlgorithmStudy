
#include "stdafx.h"

#pragma warning (disable : 4996)

int _tmain(int argc, _TCHAR* argv[])
{
    unsigned int a;
    unsigned int b;
    unsigned int c;

    scanf("%u", &a);

    for (int i = 0; i < a; i++)
    {
        scanf("%u", &b);
        c = Translate(b);
        printf("%u\n", c);
    }
    return 0;
}

