/**
 * @file IBag.h
 * @author Kyle Givler
 */

#ifndef _I_BAG_H_
#define _I_BAG_H_

#include <vector>

template <class T>
class BagInterface
{
public:
    /**
     * @return number of items in the bag
     */
    virtual size_t getSize() const = 0;
    
    /**
     * @return true if bag is empty, false otherwise
     */
    virtual bool isEmpty() const = 0;
    
    /**
     * @param item Item to be insert into bag
     * @return true on sucess, false on failure
     */
    virtual bool add(const T& item) = 0;
    
    /**
     * @param item item to remove from bag;
     * @return true on sucess, false otherwise
     */
    virtual bool remove(const T& item) = 0;
    
    /**
     * @post Bag contains no items
     */
    virtual void clear() = 0;
    
    /**
     * @param item item to be counted
     * @return Th number of occurences
     */
    virtual size_t getFrequency(const T& item) const= 0;
    
    /**
     * @param item The object to check for
     * @return true if the bag contains it, false otherwise
     */
    virtual bool contains(const T& item) const = 0;
    
    /**
     * @return Vector containing all entries in bag
     */
    virtual std::vector<T> toVector() const = 0;
    
private:
};

#endif