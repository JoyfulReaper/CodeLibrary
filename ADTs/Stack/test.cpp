/**
* Test program for Stack ADT
* @file test.cpp
* @author Kyle Givler
*/

#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack<int> mStack;
    
    cout << "Testing isEmpty(): " << mStack.isEmpty() << endl;
    cout << "Testing push(1,2,3) \n";
    mStack.push(1);
    mStack.push(2);
    mStack.push(3);
    cout << "Testing isEmpty(): " << mStack.isEmpty() << endl;
    cout << "Testing push and pop\n";
    
    while(!mStack.isEmpty())
    {
	cout << mStack.peek() << endl;
	mStack.pop();
    }
}