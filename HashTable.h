#ifndef __HASHTABLE__
#define __HASHTABLE__

#include <iostream>

#include "Student.h"
#include "Exceptions.h"

const int MAXSIZE = 100;

template <class T>
class HashTable {
    private:
        T* data[MAXSIZE];
        bool deletedF[MAXSIZE];
		int length;
    public:

        HashTable() {
            for (int i{}; i < MAXSIZE; i++) {
                data[i] = nullptr;
            }
        };

        virtual ~HashTable();

        virtual void Insert(T inVal);
        virtual T* Remove(T inVal);
        virtual int Hash(T inVal);
        virtual T* GetItem(T inVal);

        virtual bool isFull();
        virtual bool isEmpty();

        virtual int GetLength();
};

#endif
