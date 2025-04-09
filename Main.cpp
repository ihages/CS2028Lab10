//give the user options to test each function
#include <iostream>
#include <string>
#include "HashTable.h"
#include "Student.h"
#include "Exceptions.h"
#include "ChainHash.h"
#include "List.h"

HashTable<Student> OneDHash;
ChainHash<Student> ChainHashTable;
Student StudentData;

int main() {
	int choice = 0;
	std::cout << "Select which function you would like to test : \n1.Add\n2.Remove\n3.GetItem\n4.GetLength\n5.Quit" << std::endl;
	std::cin >> choice;
	while (choice != 5) {
		while (choice < 1 || choice >5) {
			std::cout << "Invalid input.Please try again." << std::endl;
			std::cin >> choice;
		}
		switch (choice) {
			case 1: {
				//need a function to get student data
				OneDHash.Insert(StudentData);
				std::cout << "Added student data to the data structure" << std::endl;
				break;
			}
			case 2: {
				//getstudentdata
				Student* retPtr{};
				retPtr = OneDHash.Remove(StudentData);
				std::cout << "Removed item at " << retPtr << std::endl;
				break;
			}
			case 3: {
				//getstudentdata
				Student* retPtr{};
				retPtr = OneDHash.GetItem(StudentData);
				if (retPtr != nullptr) {
					std::cout << "The item was found at" << retPtr << std::endl;
				}
				else {
					std::cout << "The item was not found in the structure." << std::endl;
				}
                break;
            }
			case 4: {
				int OneDHashTableLength = 0;
				OneDHashTableLength = OneDHash.GetLength();
				std::cout << "The length of the hash table is" << OneDHashTableLength << std::endl;
				break;
			}
			case 5: {
				return 0;
			}
		}
		return 0;
	}
}