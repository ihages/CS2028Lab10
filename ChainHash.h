#ifndef __CHAINHASH__
#define __CHAINHASH__

#include <iostream>

#include "Student.h"
#include "Exceptions.h"
#include "List.h"
#include "HashTable.h"

template<class T>
class ChainHash : public HashTable<T>{
private:
	List<T> data[MAXSIZE];
	int length;
public:
	ChainHash(){
		for (int i{}; i < MAXSIZE; i++) {
			data[i] = List<T>();
		}
		length = 0;
	}

	~ChainHash() override;

	void Insert(T inVal) override;
    T* Remove(T inVal) override;
    int Hash(T inVal) override;
    T* GetItem(T inVal) override;
    bool isFull() override;
    bool isEmpty() override;
    int GetLength() override;
};





#endif