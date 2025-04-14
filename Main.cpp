//give the user options to test each function
#include <iostream>
#include <string>
#include <random>
#include <time>
#include "HashTable.h"
#include "Student.h"
#include "Exceptions.h"
#include "ChainHash.h"
#include "List.h"

HashTable<Student> Hash;
ChainHash<Student> ChainHashTable;
Student StudentData;

Student inputUserStudent();
Student createRandomStudent();

int main() {
	srand(time(0));
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

Student inputUserStudent() {
	std::string firstName;
	std::string lastName;
	int mNumber;
	std::string major;

	std::cout << "Please enter the student's first name: " << std::endl;
	std::cin >> firstName;

	std::cout << "Please enter the student's last name: " << std::endl;
	std::cin >> lastName;

	std::cout << "Please enter the student's mNumber: " << std::endl;
	std::cin >> mNumber;

	std::cout << "Please enter the student's major: " << std::endl;
	std::cin >> major;

	Student temp(firstName, lastName, mNumber, major);
	return temp;
}

Student createRandomStudent() {
	std::string firstNames[] = {"Steve", "Sue", "Mark", "Sarah", "Josh", "Kelly", "Jerry", "Lisa", "Paul", "Rachel"};
	std::string lastNames[] = {"Smith", "Harvey", "North", "Bines", "O'Conner", "Lincoln", "Adams", "Johnson", "Grant", "Trump"};
	std::string majors[] = {"CS", "Biology", "Law", "Art", "Architecture", "Business", "Engineering", "English", "Gamer", "Doctor"};

	int randFName = rand() % 10;
	int randLName = rand() % 10;
	int randMNum = rand() % 10000;
	int randMJ = rand() % 10;

	Student temp(firstNames[randFName], lastNames[randLName], randMNum, majors[randMJ]);
	return temp;
}