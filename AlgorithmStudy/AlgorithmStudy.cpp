
#include "stdafx.h"

#pragma warning (disable : 4996)

int _tmain(int argc, _TCHAR* argv[])
{
    int a;
    scanf("%d", &a);

    for (int i = 0; i < a; i++)
    {
        char* in = new char[1001];
        scanf("%s", in);
        char* out;
        out = Translate2(in);
        int j = 0;
        while (in[j] != '\0')
        {
            printf("%c", out[j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}

