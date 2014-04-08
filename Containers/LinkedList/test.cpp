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
    LinkedList<int> list2;
    
    cout << "isEmpty(): " << list.isEmpty() << endl;
    cout << "numberOfItems(): " << list.numberOfItems() << endl;
    cout << "Testing insertFront()\n";
    list.insertFront(3);
    list.insertFront(2);
    list.insertFront(1);
    cout << "isEmpty(): " << list.isEmpty() << endl;
    cout << "numberOfItems(): " << list.numberOfItems() << endl;
    
    cout << "The list contains: " << list << endl;
    cout << "Inserting at end: " << endl;
    list.insertEnd(4);
    list.insertEnd(5);
    list.insertEnd(6);
    cout << "The list contains: " << list << endl;
    
    cout << "\nTesting insertByPosition(0,0): \n";
    list.insertByPosition(0,0);
    cout << "The list contains: " << list << endl;
    cout << "\nTesting insertByPosition(7,77): \n";
    list.insertByPosition(7,77);
    cout << "The list contains: " << list << endl;
    cout << "\nTesting insertByPosition(2,22): \n";
    list.insertByPosition(2,22);
    cout << "The list contains: " << list << endl;
    
    cout << "\nTesting operator=(): " << endl;
    list2 = list;
    cout << "list1: " << list << endl;
    cout << "list2: " << list2 << endl;
    
    cout << "\nTesting Copy Constructor: " << endl;
    LinkedList<int> list3(list2);
    cout << "list2: " << list << endl;
    cout << "list3: " << list2 << endl;
    
    
    return 0;
}