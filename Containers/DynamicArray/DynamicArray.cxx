/**
@file DynamicArray.cxx
@author Kyle Givler
 */

#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"
/*************************** CONSTRUCTORS **************************/

template <class T>
DynamicArray<T>::DynamicArray(size_t cap)
{
    capacity = cap;

    if(capacity < 1)
    capacity = 1;

    eltsInUse = 0;

    data = new T[capacity];
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray &original)
{
    capacity = original.capacity;
    eltsInUse = original.eltsInUse;

    if (original.data != nullptr)
    {
	data = new T[capacity];
	for(size_t i = 0; i < eltsInUse; i++)
	data[i] = original.data[i];
    } else 
    data = nullptr;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data;
}

/************************ OPERATORS ************************************/

template <class T>
DynamicArray<T> DynamicArray<T>::operator=(DynamicArray<T> rhs)
{
    capacity = rhs.capacity;
    eltsInUse = rhs.eltsInUse;
    if (data != nullptr)
    delete[] data;

    data = new T[capacity];
    if (eltsInUse != 0)
    for (size_t i = 0; i < eltsInUse; i++)
    data[i] = rhs.data[i];

    return (*this);
}

/**********************************************************************/

template <class T>
void DynamicArray<T>::print(std::ostream &out, char delimiter) const
{
    for (size_t i = 0; i < eltsInUse; i++)
    {
	out << data[i];
	if (i < eltsInUse - 1)
	out << delimiter;
    }
    out << std::endl;
}

template <class T>
void DynamicArray<T>::print() const
{
    print(std::cout, ' ');
}

template <class T>
bool DynamicArray<T>::isEmpty() const
{
    return eltsInUse == 0;
}

template <class T>
size_t DynamicArray<T>::numberOfItems()const
{
    return eltsInUse;
}

template <class T>
void DynamicArray<T>::insertFront(T item)
{
    insertByPosition(0, item);
}

template <class T>
void DynamicArray<T>::insertEnd(T item)
{
    insertByPosition(eltsInUse, item);
}

template <class T>
void DynamicArray<T>::insertByPosition(size_t index, T item) throw (std::invalid_argument)
{		
    if(eltsInUse == capacity)
    resize();

    size_t position;
    if((index>0) && (index <= eltsInUse))
    {
	for(position = eltsInUse; position >= index; position--)
	data[position] = data[position-1];

	data[index] = item;
	eltsInUse++;
	return;
    }
    else
    {	  
	if(eltsInUse > 0)
	for(position = eltsInUse; position > 0; position--)
	{
     data[position] = data[position - 1];
 }

	data[0] = item;
	eltsInUse++;
	return;
    }

    throw std::invalid_argument("Invalid index!");	
}

template <class T>	
void DynamicArray<T>::insertByValue(T item) 
{
    size_t index = 0;
    if(eltsInUse > 0)
    index = binarySearch(0, eltsInUse -1, item);

    std::cout << "DEBUG: index = " << index << std::endl; 

    insertByPosition(index, item);
}

template <class T>
void DynamicArray<T>::getFront(T &item) const
{
    item = data[0];
}

template <class T>
void DynamicArray<T>::getEnd(T &item) const
{
    item = data[eltsInUse -1];
}

template <class T>
void DynamicArray<T>::getByPosition(size_t index, T &item) const
{
    item = data[index];
}

template <class T>
void DynamicArray<T>::removeFront()
{
    for(size_t i = 0; i < eltsInUse; i++)
    data[i] = data[i + 1];
    eltsInUse--;
}

template <class T>
void DynamicArray<T>::removeEnd()
{
    eltsInUse--;
}

template <class T>
void DynamicArray<T>::removeByPosition(size_t position)
{
}

template <class T>
void DynamicArray<T>::removeByValue(T item)
{
}

template <class T>
void DynamicArray<T>::removeAll() 
{
    eltsInUse = 0;
}

template <class T>
void DynamicArray<T>::resize()
{
    //	std::cout << "DEBUG: resizing\n";

    capacity = capacity * 1.5;

    T *newData = new T[capacity];
    for(size_t i = 0; i < eltsInUse; i++)
    newData[i] = data[i];

    delete[] data;
    data = newData;
}

/* broken... */
template <class T>
size_t DynamicArray<T>::binarySearch(size_t first, size_t last, const T &key)
{
    size_t index;
    if(first > last)
    index = -1;
    else {
	int mid = first + (last - first) / 2;
	index = mid;
	if(key == data[mid])
	index = mid;
	else if(key < data[mid])
	index = binarySearch(first, mid -1, key);
	else
	index = binarySearch(mid + 1, last, key);
      }
    return index;
}

