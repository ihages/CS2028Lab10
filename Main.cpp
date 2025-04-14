//give the user options to test each function
#include <iostream>
#include <string>
#include "HashTable.h"
#include "Student.h"
#include "Exceptions.h"
#include "ChainHash.h"
#include "List.h"

HashTable<Student> Hash;
ChainHash<Student> ChainHashTable;
Student StudentData;

int main() {
	int choice = 0;
	while (true) {
		std::cout << "Select which function you would like to test: \n1.Add\n2.Remove\n3.GetItem\n4.GetLength\n5.Quit" << std::endl;
		std::cin >> choice;
			switch (choice) {
				case 1: {
					//need a function to get student data
					Hash.Insert(StudentData);
					std::cout << "Added student data to the data structure" << std::endl;
					break;
				}
				case 2: {
					//getstudentdata
					Student* retPtr{};
					retPtr = Hash.Remove(StudentData);
					std::cout << "Removed item at " << retPtr << std::endl;
					break;
				}
				case 3: {
					//getstudentdata
					Student* retPtr{};
					retPtr = Hash.GetItem(StudentData);
					if (retPtr != nullptr) {
						std::cout << "The item was found at" << retPtr << std::endl;
					}
					else {
						std::cout << "The item was not found in the structure." << std::endl;
					}
					break;
				}
				case 4: {
					int HashTableLength = 0;
					HashTableLength = Hash.GetLength();
					std::cout << "The length of the hash table is " << HashTableLength << std::endl;
					break;
				}
				case 5: {
					return 0;
				}
				default: {
					std::cout << "Please enter a valid input" << std::endl;
					break;
				}
			}
			
	}
	return 0;
}