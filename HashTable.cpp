#include "HashTable.h"

template <class T>
HashTable<T>::~HashTable() {

}

template <class T>
void HashTable<T>::Insert(T inVal) {
    if (isFull()) {
        throw Exception(-1, "Hash Table is full");
    }

    //If location you want add at is taken add move up a space
    int index = Hash(inVal);
    while(data[index] != nullptr) {
        index = (index + 1) % MAXSIZE;
    }
    data[index] = new T(inVal);
}

template <class T>
T* HashTable<T>::Remove(T target) {
    GetItem(target);
    int index = Hash(target);

    while(*data[index] != target) {
        index = (index + 1) % MAXSIZE;
    }
    T* retVal = data[index];
    deletedF[index] = true;
    data[index] = nullptr;
    return retVal;
}

template <class T>
int HashTable<T>::Hash(T inVal) {
    return inVal % MAXSIZE;
}

template <class T>
T* HashTable<T>::GetItem(T target) {
    int index = Hash(target);
    try {
        if (data[index] == nullptr) {   //nullptr in place of NULL
            throw Exception(-1, "Unable to find value in Hash Table");
        }
        while (!(*data[index] == target) && !(data[index] == nullptr) && (data[index] == nullptr && deletedF[index] == false)) {
            index = (index + 1) % MAXSIZE;
        }
        if (data[index] == nullptr) {   //nullptr in place of NULL
            throw Exception(-1, "Unable to find value in Hash Table");
        }
	}
	catch (Exception& e) {
		return nullptr;
	}
    return data[index];
}

template <class T>
bool HashTable<T>::isFull() {
    for (int i{}; i < MAXSIZE; i++) {
        if (data[i] == nullptr) {   //Check for a value that isnt filled
            return false;
        }
    }
    return true;
}

template <class T>
bool HashTable<T>::isEmpty() {
    for (int i{}; i < MAXSIZE; i++) {
        if (data[i] != nullptr) {   //Check for a value that is filled
            return false;
        }
    }
    return true;
}


template<class T>
int HashTable<T>::GetLength() {
    return length;
}

template class HashTable<Student>;
