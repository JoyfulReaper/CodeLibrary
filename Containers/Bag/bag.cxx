/**
 * @file bag.cxx
 * @author Kyle Givler
 * 
 * A Dynmaic Array Based Bag ADT
 */

#include <stdexcept>
#include <algorithm>

template <class T>
Bag<T>::Bag()
{
    itemCount = 0;
    data = new DynamicArray<T>;
}

template<class T>
Bag<T>::Bag(size_t init_size)
{
    itemCount = 0;
    data = new DynamicArray<T>(init_size);
}

template<class T>
Bag<T>::~Bag()
{
    delete data;
}

template <class T>
inline size_t Bag<T>::getSize() const
{
    return itemCount;
}

template <class T>
inline bool Bag<T>::isEmpty() const
{
    return (!itemCount);
}

template <class T>
bool Bag<T>::add(const T& item)
{
    data->insertEnd(item);
    itemCount++;
    
    return true;
}

template <class T>
bool Bag<T>::remove(const T& item)
{
    return data->removeByValue(item);
}


template <class T>
void Bag<T>::clear()
{
    data->removeAll();
}

template <class T>
bool Bag<T>::contains(const T& item) const
{
    return false;
}

template <class T>
size_t Bag<T>::getFrequency(const T& item) const
{
    return 0;
}

template <class T>
std::vector<T> Bag<T>::toVector() const
{
    std::vector<T> v;
    return v;
}

template <class T>
size_t Bag<T>::getIndexOf(const T& item) const throw(std::out_of_range)
{
    return 0;
}
