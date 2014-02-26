/**
 *	@file DynamicArray.h
 *	@author Kyle Givler
 */

#ifndef _DYNAMIC_ARRAY_H_
#define _DYNAMIC_ARRAY_H_

#include "../IContainer.h"
#include <stdexcept>

template<class T>
class DynamicArray : public IContainer<T>
{
public:
    /**
     *Capacity must be >= 1, if not it will be set to 1
     *@param capacity Initial capacity of the array
     */
    DynamicArray(size_t capacity = 10);
    
    DynamicArray(const DynamicArray &original);
    
    ~DynamicArray();
    
    DynamicArray operator=(DynamicArray rhs);
    
    /**
    * Returns null if index is out of bounds
    */
    T &operator[](size_t index);
    
    /**
     *Prints out the contents of the array
     *@pre none
     *@param out The stream to print to
     *@param delimiter Character to use between elements
     */
    void print(std::ostream &out, char delimiter = ' ') const;
    
    void print() const;
    
    /** @return True if list is empty; false otherwise */
    bool isEmpty() const;
    
    /** @return The number of items in the container */
    size_t numberOfItems() const;
    
    /** 
     *Inserts an item into the front of the container
     *@pre none
     *@param item The item to insert into the container 
     */
    void insertFront(T item);
    
    /** 
     *Inserts an item into the back of the container
     *@pre none
     *@param item The item to insert into the container 
     */
    void insertEnd(T item);
    
    /** 
     *	Inserts an item into the container at the specified position
     *	@pre none
     *	@param index The index in the container at which to insert the item
     *	@param item The item to insert into the container 
     */
    void insertByPosition(size_t index, T item) throw(std::invalid_argument);
    
    /**
     * Inserts items in ascending order
     * @pre Array is sorted in ascending order
     * @param anItem The item to insert
     */
    void insertByValue(T anItem);
    
    /**
     *	Gets the item at the front of the container
     *	@pre The container is not empty
     *	@post item contains the item from the front of the container
     *	@param item Will hold the item from the front of the container
     */
    void getFront(T &item) const throw(std::out_of_range);
    
    /**
     *	Gets the item at the back of the container
     *	@pre The container is not empty
     *	@post item contains the item from the back of the container
     *	@param item Will hold the item from the front of the container
     */
    void getEnd(T &item) const throw(std::out_of_range);
    
    /**
     *	Gets the item at the specified index
     *	@pre The container is not empty and index is a valid index
     *	@post item contains the item from the specified index of the container
     *	@param item Will hold the item from the front of the container
     */
    void getByPosition(size_t index, T &item) const throw(std::out_of_range);
    
    /**
     *	Removes the item at the front of the container
     *	@pre The container is not empty
     *	@post The item at the front of the container has been removed
     */
    void removeFront() throw(std::out_of_range);
    
    /**
     *	Removes the item at the back of the container
     *	@pre The container is not empty
     *	@post The item at the back of the container has been removed
     */
    void removeEnd() throw(std::out_of_range);
    
    /**
     *	Removes the item at the specified index of the container
     *	@pre The container is not empty and index is a valid index
     *	@post The item at the specified index of the container has been removed
     */
    void removeByPosition(size_t position) throw(std::invalid_argument);
    
    /**
     * @param item The item to remove from the container
     * @return true if the item was removed; false otherwise
     */
    bool removeByValue(T item); 
    
    /**
     *	Removes all of the items from the container
     *	@pre none
     *	@post The container is empty
     */
    void removeAll();
    
    /**
     * Swap the elements in index1 and index2
     * @pre index1 and index2 are valid indexes
     */
    void swap(size_t index1, size_t index2) throw(std::out_of_range);
    
private:
    size_t capacity;
    size_t eltsInUse;
    T *data = nullptr; // pointer to an array of type T
    
    void resize();
};

#include "DynamicArray.cxx"
#endif
