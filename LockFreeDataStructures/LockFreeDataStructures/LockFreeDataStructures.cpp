// LockFreeDataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;
int main()
{
    lockless_linked_list<int> value(5);
    value.insert(10, 0);
    value.insert(20, 1);
    value.insert(39, 2);
    value.remove(2);
    value.print([](const int &value) { cout << value << endl; });
    return 0;
}

