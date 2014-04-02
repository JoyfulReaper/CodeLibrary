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
    cout << "Testing insertByValue() 3, 4, 1, 5, 2\n";
    dyn4.insertByValue(3);
    dyn4.print();
    dyn4.insertByValue(4);
    dyn4.print();
    dyn4.insertByValue(1);
    dyn4.print();
    dyn4.insertByValue(5);
    dyn4.print();
    dyn4.insertByValue(2);
    dyn4.print();
    cout << "Testing numberOfItems(): " << dyn4.numberOfItems() << std::endl;
    cout << "Testing insertByPosition(2, 99): ";
    dyn4.insertByPosition(2, 99);
    dyn4.print();
    int front;
    dyn4.getFront(front);
    cout << "Testing getFront(): " << front << std::endl;
    int back;
    dyn4.getEnd(back);
    cout << "Testing getEnd(): " << back << std::endl;
    dyn4.print();
    int position;
    dyn4.getByPosition(2, position);
    cout << "Testing getByPosition(2): " << position << std::endl;
    dyn4.removeFront();
    cout << "Testing removeFront(): " << "\n" << dyn4;
    dyn4.removeEnd();
    cout << "Testing removeEnd(): " << "\n" << dyn4;
    dyn4.removeByPosition(2);
    cout << "Testing removeByPosition(2): " << "\n" << dyn4;
    dyn4.removeByValue(99);
    cout << "Testing removeByValue(99): " << "\n" << dyn4;
    dyn4.removeAll();
    cout << "Testing removeAll(): " << "\n" << dyn4;
    
    DynamicArray<int> test;
    test.insertEnd(5);
    test.insertEnd(4);
    test.insertEnd(3);
    test.insertEnd(2);
    
    cout << "Testing overloaded operators: " << test << std::endl;
    cout << "Testing test[1]: " << test[1] << endl;
    cout << "Testing test[1] = 300: " << endl;
    test[1]=300;
    cout << "Testing test[1]: " << test[1] << endl;
   
    return 0;
}
