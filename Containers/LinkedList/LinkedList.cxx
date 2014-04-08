/**
 * LinkedList Implementation
 * @file LinkedList.cxx
 * @author Kyle Givler
 */

/*************************** CONSTRUCTORS **************************/

template <class T>
LinkedList<T>::LinkedList()
{
    numberOfNodes = 0;
    head = nullptr;
    tail = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList &orginal)
{
    numberOfNodes = orginal.numberOfNodes;
}

template <class T>
LinkedList<T>::~LinkedList()
{
}

/*******************************************************************/

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList &rhs)
{
    return (*this);
}

template <class T>
void LinkedList<T>::print(std::ostream &out, char del) const
{
    node *current = head;
    while(true)
    {
	out << current->data;
	current = current->next;
	if (current == nullptr)
	{
	    break;
	}
	else
	{
	    out << del;
	}
    }
    out << std::endl;
}

/*******************************************************************/

template <class T>
bool LinkedList<T>::isEmpty() const
{
    return (!numberOfNodes);
}

template <class T>
size_t LinkedList<T>::numberOfItems() const
{
    return numberOfNodes;
}

template <class T>
void LinkedList<T>::insertFront(T item)
{
    node *oldHead = head;
    head = new node(item, oldHead);
    numberOfNodes++;
}

template <class T>
void LinkedList<T>::insertEnd(T item)
{
    node *current;
    
    if (head == nullptr)
	head = new node(item, nullptr);
    else
    {
	current = head;
	while(current->next != nullptr)
	    current = current->next;
	
	current->next = new node(item, nullptr);
    }
}

template <class T>
void LinkedList<T>::insertByPosition(size_t index, T item)
{
}

template <class T>
void LinkedList<T>::insertByValue(T anItem)
{
}

template <class T>
void LinkedList<T>::getFront(T &item) const
{
}

template <class T>
void LinkedList<T>::getEnd(T &item) const
{
}

template <class T>
void LinkedList<T>::getByPosition(size_t index, T &item) const
{
}

template <class T>
void LinkedList<T>::removeFront()
{
}

template <class T>
void LinkedList<T>::removeEnd()
{
}

template <class T>
void LinkedList<T>::removeByPosition(size_t position)
{
}

template <class T>
bool LinkedList<T>::removeByValue(T item)
{
    return false;
}

template <class T>
void LinkedList<T>::removeAll()
{
}

/*******************************************************************/

template <class T>
std::ostream& operator<<(std::ostream &out, const LinkedList<T> &list)
{
    list.print(out, ' ');
    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, LinkedList<T> &list)
{
    return in;
}