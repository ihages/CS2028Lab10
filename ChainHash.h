#ifndef __CHAINHASH__
#define __CHAINHASH__

#include <iostream>

#include "Student.h"
#include "Exceptions.h"
#include "List.h"

template<class T>
class ChainHash : public HashTable{
private:
	List<T> data[MAXSIZE];
	int length;
public:
	ChainHash(){
		for (int i{}; i < MAXSIZE; i++) {
			data[i] = nullptr;
		}
	}

	~ChainHash();

	void Insert(T inVal);
	T* Remove(T inVal);
	int Hash(T inVal);
	T* GetItem(T inVal);

	bool isFull();
	bool isEmpty();

	int GetLength();

};





#endif