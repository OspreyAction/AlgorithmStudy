// AlgorithmStudy.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#pragma warning (disable : 4996)

int _tmain(int argc, _TCHAR* argv[])
{
    double a, b;

    scanf("%lf %lf", &a, &b);

    printf("%d\n", IsEqual(a, b));

	return 0;
}

