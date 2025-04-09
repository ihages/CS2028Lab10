#ifndef __HASHTABLE__
#define __HASHTABLE__

#include <iostream>

#include "Student.h"
#include "Exceptions.h"

const int MAXSIZE = 100;

template <class T>
class HashTable {
    private:
        T data[MAXSIZE];
        bool deletedF[MAXSIZE];
		int length;
    public:

        HashTable() {
            for (int i{}; i < MAXSIZE; i++) {
                data[i] = nullptr;
            }
        };

        ~HashTable();

        void Insert(T inVal);
        T* Remove(T inVal);
        int Hash(T inVal);
	    T* GetItem(T inVal); 
        void Print();

        bool isFull();
        bool isEmpty();

        int GetLength();
};

#endif
