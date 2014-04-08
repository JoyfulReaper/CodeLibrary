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
    Bag(size_t init_size = 10); //Initial size for array
    Bag(const Bag<T> &org);
    ~Bag();
    
    Bag<T>& operator=(const Bag<T> &rhs);
    bool operator==(const Bag<T> &other) const;
    bool operator!=(const Bag<T> &other) const;
    Bag<T>& operator+=(const T &rhs);
    Bag<T>& operator-=(const T &rhs);
    
     /**
     * @return number of items in the bag
     */
     size_t getSize() const;
    
     /**
     * @return true if bag is empty, false otherwise
     */
    bool isEmpty() const;
    
     /**
     * @param item Item to be insert into bag
     * @return true on sucess, false on failure
     */
    bool add(const T& item);
    
     /**
     * @param item item to remove from bag;
     * @return true on sucess, false otherwise
     */
    bool remove(const T& item);
    
     /**
     * @post Bag contains no items
     */
    void clear();
    
     /**
     * @param item The object to check for
     * @return true if the bag contains it, false otherwise
     */
    bool contains(const T& item) const;
    
     /**
     * @param item item to be counted
     * @return The number of occurences
     */
    size_t getFrequency(const T& item) const;
    
     /**
     * @return Vector containing all entries in bag
     */
    std::vector<T> toVector() const;
    
    void print(std::ostream &out, char delim = ' ') const;
    void print() const { print(std::cout, ' '); }
    
private:
   size_t itemCount; // Number of items in bag
   DynamicArray<T> *data = nullptr;
};

#include "bag.cxx"
#endif