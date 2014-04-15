/**
 * Stack ADT
 * @file stack.cxx
 * @author Kyle Giver
 */


template<class T>
Stack<T>::Stack(size_t size)
{
    numItems = 0;
    data = new DynamicArray<T>(size);
}

template<class T>
Stack<T>::Stack(const Stack &org)
{
    numItems = org.numItems;
    data = new DynamicArray<T>(numItems * 1.5);
    T item;
    for(size_t i = 0; i < numItems; i++)
    {
	org.data->getByPosition(i, item);
	data->insertByPosition(i, item);
    }
}

template<class T>
Stack<T>::~Stack()
{
    data->removeAll();
    delete data;
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return (numItems == 0);
}

template <class T>
bool Stack<T>::push(const T& item)
{
    data->insertEnd(item);
    numItems++;
    return true;
}

template <class T>
bool Stack<T>::pop()
{
    if (numItems == 0)
	return false;
    
    data->removeEnd();
    numItems--;
    return true;
}

template <class T>
T Stack<T>::peek() const
{
    T item;
    data->getByPosition(numItems - 1, item);
    return item;
}
