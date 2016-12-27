
#include "stdafx.h"

#pragma warning (disable : 4996)

int _tmain(int argc, _TCHAR* argv[])
{
    CListStudy List;

    List.AddNode(3);
    List.AddNode(5);
    List.AddNode(7);
    List.AddNode(9);
    List.AddNode(11);
    List.AddNode(13);
    List.AddNode(15);

    List.PrintForward();
    List.DeleteNode(3);
    List.PrintBackward();
    List.PrintElements();
}

