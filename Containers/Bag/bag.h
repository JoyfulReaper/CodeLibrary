/**
 * @file bag.h
 * @author Kyle Givler
 * 
 * A Dynmaic Array Based Bag ADT
 */

#ifndef _BAG_H__
#define _BAG_H__

#include <stdexcept>

#include "IBag.h"
#include "../DynamicArray/DynamicArray.h"

template<class T>
class Bag : public BagInterface<T>
{
public:
    Bag();
    Bag(size_t init_size); //Initial size for array
    //Bag(const T& org);
    
    ~Bag();
    
    inline size_t getSize() const;
    inline bool isEmpty() const;
    bool add(const T& item);
    bool remove(const T& item);
    void clear();
    bool contains(const T& item) const;
    size_t getFrequency(const T& item) const;
    std::vector<T> toVector() const;
    
private:
   size_t itemCount; // Number of items in bag
   DynamicArray<T> *data = nullptr;
   
   // Get index of item
   size_t getIndexOf(const T& item) const throw(std::out_of_range);
};

#include "bag.cxx"
#endif