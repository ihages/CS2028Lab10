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
    length++;
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
    length--;
    return retVal;
}

template <class T>
int HashTable<T>::Hash(T inVal) {
    return inVal % MAXSIZE;
}

template <class T>
T* HashTable<T>::GetItem(T target) {
    int index = Hash(target);
    int startIndex = index;

    do {
        // Skip deleted slots
        if (data[index] == nullptr && deletedF[index] == true) {
            index = (index + 1) % MAXSIZE;
            continue;
        }

        // If we found a non-null slot with matching data
        if (data[index] != nullptr && *data[index] == target) {
            return data[index];
        }

        // If we found an empty slot (not deleted), the item doesn't exist
        if (data[index] == nullptr && !deletedF[index]) {
            throw Exception(-1, "Unable to find value in Hash Table");
        }

        // Move to next slot
        index = (index + 1) % MAXSIZE;
    } while (index != startIndex);
    throw Exception(-1, "Unable to find value in Hash Table");
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
