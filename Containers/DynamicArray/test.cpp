/**
Test program for DynamicArray ADT
@file test.cpp
@author Kyle Givler
 */

#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    DynamicArray<int> dyn;

    cout << "isEmpty(): " << dyn.isEmpty() << endl;

    cout << "testing insertEnd: 1, 2, 3 \n";
    dyn.insertEnd(1);
    dyn.insertEnd(2);
    dyn.insertEnd(3);
    dyn.print(cout);

    cout << "isEmpty(): " << dyn.isEmpty() << endl;
    cout << "numberOfItems(): " << dyn.numberOfItems() << endl;

    cout << "testing insertFront: 99, 98, 97 \n";
    dyn.insertFront(99);
    dyn.insertFront(98);
    dyn.insertFront(97);
    dyn.print(cout);

    cout << "Testing removeFront\n";
    dyn.removeFront();
    dyn.print();

    cout << "Testing removeEnd\n";
    dyn.removeEnd();
    dyn.print();

    cout << "Testing copy constructor\n";
    DynamicArray<int> dyn2(dyn);
    dyn2.print(cout);

    cout << "Testing equal operator\n";
    DynamicArray<int> dyn3;
    dyn3 = dyn2;
    dyn3.print(cout);

    DynamicArray<int> dyn4;
    cout << "Testing insertByValue() 9, 3, 1, 7, 45, 300, 2, 2\n";
    dyn4.insertByValue(9);
    dyn4.insertByValue(3);
    dyn4.insertByValue(1);
    dyn4.insertByValue(7);
    dyn4.insertByValue(45);
    dyn4.insertByValue(300);
    dyn4.insertByValue(2);
    dyn4.insertByValue(2);
    dyn4.print();

    return 0;
}
