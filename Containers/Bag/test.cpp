/**
Test program for DynamicArray ADT
@file test.cpp
@author Kyle Givler
 */

#include <iostream>
#include "bag.h"

using namespace std;

int main()
{
    Bag<int> mBag;
    
    cout << "size: " << mBag.getSize() << endl;
    cout << "isEmpty(): " << mBag.isEmpty() << endl;
    cout << "adding 1,2,3...\n";
    mBag.add(1);
    mBag.add(2);
    mBag.add(3);
    cout << "size: " << mBag.getSize() << endl;
    cout << "isEmpty(): " << mBag.isEmpty() << endl << endl;
    cout << "Contents: " << mBag;
    Bag<int> mBag2;
    cout << "\nTesting equal operator: ";
    mBag2 = mBag;
    cout << mBag2;
    cout << "Testing copy constructor: ";
    Bag<int> mBag3(mBag2);
    cout << mBag3;
    
    cout << "\nTesting remove(2): ";
    mBag3.remove(2);
    cout << mBag3;
    
    cout << "\nTesting clear(): ";
    mBag3.clear();
    cout << mBag3;
    
    cout << "\nTesting contains(3): " << mBag2.contains(3) << endl;
    mBag2.contains(3);
    cout << mBag2;
    cout << "\nTesting contains(7): " << mBag2.contains(3) << endl;
    mBag2.contains(7);
    cout << mBag2;
    return 0;
}