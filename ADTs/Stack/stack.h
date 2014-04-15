/**
 * Stack ADT
 * @file stack.h
 * @author Kyle Giver
 */

#ifndef __STACK_H
#define __STACK_H

#include "IStack.h"
#include "../DynamicArray/DynamicArray.h"

template <class T>
class Stack : public StackInterface<T>
{
public:
    
    /**
     * Initialize the stack
     * @param Initialize Initial size of the array
     */
    Stack(size_t intialSize = 10);
    Stack(const Stack &org);
    ~Stack();
    
    Stack<T>& operator=(const Stack<T> &rhs);
    
    /**
     * Check if the stack is isEmpty
     * @return true if empty, otherwise false
     */
    bool isEmpty() const;
    
    /**
     * Add new entry at top of stack
     * @param  The object to be added
     * @return true in success, false on failure
     */
    bool push(const T& data);
    
    /**
     * Remove the item on the top of the stack
     * @return true on success, false on failure
     */
    bool pop();
    
    /**
     * Returns the object on the top of the stack
     * @return The top of the stack
     */
     T peek() const;
private:
    size_t numItems;
    DynamicArray<T> *data;
};

#include "stack.cxx"

#endif