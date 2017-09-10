/**
*	@file : node.hpp
*	@author :  Luke Dercher
*	@date : 2017.08.25
*	Purpose: Implementation file of templated double linked node class.
*/
#include "node.hpp"

template <class T>
node<T>::node()
{
    m_next = nullptr;

    m_prev = nullptr;

    m_value = T();

    m_coord = make_tuple(0,0);

}

template <class T>
void node<T>::setCoord(int x,int y)
{
    m_coord = make_tuple( x,y );
}

template <class T>
tuple<int,int> node<T>::getCoord()
{
    return m_coord;
}

template <class T>
void node<T>::setValue(T value)
{
    m_value = value;
}

template <class T>
T node<T>::getValue()
{
    return m_value;
}

template <class T>
void node<T>::setNext(node<T>* n)
{
    m_next = n;
}

template <class T>
node<T>* node<T>::getNext()
{
    return m_next;
}

template <class T>
void node<T>::setPrev (node<T>* n)
{
    m_prev = n;
}

template <class T>
node<T>* node<T>::getPrev()
{
    return m_prev;
}
