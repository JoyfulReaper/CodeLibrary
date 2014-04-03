/**
 * @file bag.h
 * @author Kyle Givler
 * 
 * A Dynmaic Array Based Bag ADT
 */

#ifndef _BAG_H__
#define _BAG_H__

#include "IBag.h"
#include "../DynamicArray/DynamicArray.h"

template<class T>
class Bag : public BagInterface<T>
{
public:
    Bag();
    Bag(size_t init_size); //Initial size for array
    Bag(const Bag &org);
    
    ~Bag();
    
    inline size_t getSize() const;
    inline bool isEmpty() const;
    bool add(const T& item);
    bool remove(const T& item);
    void clear();
    bool contains(const T& item) const;
    size_t getFrequency(const T& item) const;
    std::vector<T> toVector() const;
    void print(std::ostream &out, char delim) const;
    void print() const { print(std::cout, ' '); }
    
    Bag& operator=(const Bag &rhs);
private:
   size_t itemCount; // Number of items in bag
   DynamicArray<T> *data = nullptr;
};

#include "bag.cxx"
#endif