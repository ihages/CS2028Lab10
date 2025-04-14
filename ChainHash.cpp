#include "ChainHash.h"

template<class T>
ChainHash<T>::~ChainHash() {
	for (int i{}; i < MAXSIZE; i++) {
		data[i].~List();
	}
}

template <class T>
void ChainHash<T>::Insert(T inVal) {
	int index = Hash(inVal);
	data[index].AddItem(inVal);
	length++;
}

template <class T>
T* ChainHash<T>::Remove(T target) {
	int index = Hash(target);
	if (data[index].IsEmpty()) {
		throw Exception(-1, "Item not found in ChainHash");
	}

	T temp = data[index].GetItem(target);
	T* retVal = new T(temp);
	length--;
	return retVal;
}


template <class T>
int ChainHash<T>::Hash(T inVal) {
    return inVal % MAXSIZE;
}

template <class T>
T* ChainHash<T>::GetItem(T target) {
	int index = Hash(target);
	if (data[index].IsEmpty()) {
		Exception(-1, "Item not found in the list");
	}
	T temp = data[index].GetItem(target);
	return new T(temp);
}

template <class T>
bool ChainHash<T>::isFull() {
    return false; //will never be full bc of linked list
}

template <class T>
bool ChainHash<T>::isEmpty() { //only need to check the first dimension because you can't have a 2nd dimension without the first being full
	return length == 0;
}


template<class T>
int ChainHash<T>::GetLength() {
    return length;
}

template class ChainHash<Student>;
