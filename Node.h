#ifndef __NODE__H
#define __NODE__H

#include "Part.h"

template<class T>
class Node {
    public:
        T data;
        Node<T> *next;
        Node<T> *prev;
    
        //Constructors
        Node() : data(T()), next(nullptr), prev(nullptr) {};
        Node(T inVal) : data(inVal), next(nullptr), prev(nullptr) {};
};









#endif