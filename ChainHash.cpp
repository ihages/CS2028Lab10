#include"ChainHash.h"

template<class T>
ChainHash<T>::~ChainHash() {
	for (int i{}; i < MAXROWS; i++) {
		data[i].~List();
	}
}

template <class T>
void ChainHash<T>::Insert(T inVal) {
    if (isFull()) {
        Exception(-1, "Hash Table is full");
    }
	int index = Hash(inVal);
	if (data[index].isEmpty()) {
		data[index].AddItem(inVal);
	}
	else {
		//Check if the item is already in the list
		T* temp = data[index].GetItem(inVal);
		if (temp == nullptr) {
			data[index].AddItem(inVal);
		}
		else {
			Exception(-1, "Item already exists in the list");
		}
	}
    //modify for 2D
}

template <class T>
T* ChainHash<T>::Remove(T target) {
    GetItem(target);
    int index = Hash(target);
	if (data[index].isEmpty()) {
		Exception(-1, "Item not found in the list");
	}
	else {
		T* retVal = data[index].RemoveItem(target);
		return retVal;
	}
}


template <class T>
int ChainHash<T>::Hash(T inVal) {
    return inVal % MAXSIZE;
}

template <class T>
T* ChainHash<T>::GetItem(T target) {
	int index = Hash(target);
	if (data[index].isEmpty()) {
		Exception(-1, "Item not found in the list");
	}
	else {
		T* retVal = data[index].GetItem(target);
	}
    //modify for 2D
}

template <class T>
bool ChainHash<T>::isFull() {
    return false; //will never be full bc of linked list
}

template <class T>
bool ChainHash<T>::isEmpty() { //only need to check the first dimension because you can't have a 2nd dimension without the first being full
    for (int i{}; i < MAXSIZE; i++) {
        if (data[i] != INT_MIN) {   //Check for a value that is filled
            return false;
        }
    }
    return true;
}


template<class T>
int ChainHash<T>::GetLength() {
    return length;
}

template class ChainHash<Student>;
