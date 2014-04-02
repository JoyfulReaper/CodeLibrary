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
    
    return 0;
}