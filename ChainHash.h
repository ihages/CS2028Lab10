#ifndef __CHAINHASH__
#define __CHAINHASH__

#include <iostream>

#include "Student.h"
#include "Exceptions.h"
#include "List.h"

const int MAXROWS = 100;

template<class T>
class ChainHash {
private:
	List data[MAXROWS];
	int length;
	int size;
public:
	ChainHash(){
		for (int i{}; i < MAXROWS; i++) {
			data[i] = nullptr;
		}
	}

	~ChainHash();

	void Insert(T inVal);
	T* Remove(T inVal);
	int Hash(T inVal);
	T* GetItem(T inVal);
	void Print();

	bool isFull();
	bool isEmpty();

	int GetLength();
	int GetSize();

};





#endif