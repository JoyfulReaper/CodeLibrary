/**
 * @file bag.cxx
 * @author Kyle Givler
 * 
 * A Dynmaic Array Based Bag ADT
 */

#include <stdexcept>

template <class T>
Bag<T>::Bag()
{
}

template<class T>
Bag<T>::Bag(size_t init_size)
{
}

template <class T>
size_t Bag<T>::getSize() const
{
    return 0;
}

template <class T>
bool Bag<T>::isEmpty() const
{
    return true;
}

template <class T>
bool Bag<T>::add(const T& item)
{
    return false;
}

template <class T>
bool Bag<T>::remove(const T& item)
{
    return false;
}

template <class T>
void Bag<T>::clear()
{
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
