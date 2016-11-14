
#include "stdafx.h"

#pragma warning (disable : 4996)

int _tmain(int argc, _TCHAR* argv[])
{
    double a, b;

    scanf("%lf %lf", &a, &b);

    printf("%d\n", IsEqual(a, b));

	return 0;
}

