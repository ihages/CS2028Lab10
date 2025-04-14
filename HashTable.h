#ifndef __HASHTABLE__
#define __HASHTABLE__

#include <iostream>

#include "Student.h"
#include "Exceptions.h"


template <class T>
class HashTable {
    private:
		int MAXSIZE;
        T** data;
        bool* deletedF;
		int length;
    public:

        HashTable() {
            MAXSIZE = 100;
			data = new T*[MAXSIZE];
            for (int i{}; i < MAXSIZE; i++) {
                data[i] = nullptr;
            }
        };
        HashTable(int newsize) {
            MAXSIZE = newsize;
			data = new T*[MAXSIZE];
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

        virtual int GetItemTouches(T target);
};

#endif
