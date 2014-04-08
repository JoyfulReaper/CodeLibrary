/**
 * Test program for LinkedList ADT
 * @file test.cpp
 * @author Kyle Givler
 */

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list;
    
    cout << "isEmpty(): " << list.isEmpty() << endl;
    cout << "numberOfItems(): " << list.numberOfItems() << endl;
    cout << "Testing insertFront()\n";
    list.insertFront(3);
    list.insertFront(2);
    list.insertFront(1);
    cout << "isEmpty(): " << list.isEmpty() << endl;
    cout << "numberOfItems(): " << list.numberOfItems() << endl;
    
    cout << "The list contains: " << list;
    cout << "Inserting at end: " << endl;
    list.insertEnd(4);
    list.insertEnd(5);
    list.insertEnd(6);
    cout << "The list contains: " << list;
    
    return 0;
}