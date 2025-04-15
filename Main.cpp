//give the user options to test each function
#include <iostream>
#include <string>
//#include <random>
#include<cstdlib>
#include <ctime>
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
Student mNumSearch();

int main() {
	srand(time(0));
	int tabletype = 0;
	while (true) {
		std::cout << "Which table would you like to test?\n1. Hash Table\n2. Chain Hash Table\n3. Compare Find Touches\n4. Quit" << std::endl;
		std::cin >> tabletype;
		switch (tabletype) {
		case 1: {
			int choice = 0;
			bool hashbool = true;
			while (hashbool) {
				try {
					std::cout << "Select which function you would like to test: \n1.Add\n2.Remove\n3.GetItem\n4.GetLength\n5.Return" << std::endl;
					std::cin >> choice;
					switch (choice) {
					case 1: {
						//need a function to get student data
						Student StudentData = inputUserStudent();
						Hash.Insert(StudentData);
						std::cout << "Added student data to the data structure" << std::endl;
						break;
					}
					case 2: {
						//getstudentdata
						Student StudentData = mNumSearch();
						Student* retPtr{};
						retPtr = Hash.Remove(StudentData);
						std::cout << "Removed student " << *retPtr << std::endl;
						break;
					}
					case 3: {
						//getstudentdata
						Student StudentData = mNumSearch();
						Student* retPtr{};
						retPtr = Hash.GetItem(StudentData);
						std::cout << "Student " << *retPtr << " was found" << std::endl;
						break;
					}
					case 4: {
						int HashTableLength = 0;
						HashTableLength = Hash.GetLength();
						std::cout << "The length of the hash table is " << HashTableLength << std::endl;
						break;
					}
					case 5: {
						hashbool = false;
						break;
					}
					default: {
						std::cout << "Please enter a valid input" << std::endl;
						break;
					}
					}
				}
				catch (Exception& e) {
					std::cout << e.errorNumber << " : " << e.errorMessage << std::endl;
				}
			}
			break;
		}
		case 2: {
			int choice = 0;
			bool chainbool = true;
			while (chainbool) {
				try {
					std::cout << "Select which function you would like to test: \n1.Add\n2.Remove\n3.GetItem\n4.GetLength\n5.Return" << std::endl;
					std::cin >> choice;
					switch (choice) {
					case 1: {
						//need a function to get student data
						Student StudentData = inputUserStudent();
						ChainHashTable.Insert(StudentData);
						std::cout << "Added student data to the data structure" << std::endl;
						break;
					}
					case 2: {
						//getstudentdata
						Student StudentData = mNumSearch();
						Student* retPtr{};
						retPtr = ChainHashTable.Remove(StudentData);
						std::cout << "Removed student " << *retPtr << std::endl;
						break;
					}
					case 3: {
						//getstudentdata
						Student StudentData = mNumSearch();
						Student* retPtr{};
						retPtr = ChainHashTable.GetItem(StudentData);
						if (retPtr == nullptr) {
							std::cout << "The student was not found in the structure." << std::endl;
						}
						else {
							std::cout << "Student " << *retPtr << " was found" << std::endl;
						}

						break;
					}
					case 4: {
						int HashTableLength = 0;
						HashTableLength = ChainHashTable.GetLength();
						std::cout << "The length of the hash table is " << HashTableLength << std::endl;
						break;
					}
					case 5: {
						chainbool = false;
						break;
					}
					default: {
						std::cout << "Please enter a valid input" << std::endl;
						break;
					}
					}
				}
				catch (Exception& e) {
					std::cout << e.errorNumber << " : " << e.errorMessage << std::endl;
				}
			}
			break;
		}
		case 3: {
			int testDataTable[4][3] = { {50, 0, 0}, {150, 0, 0}, {200, 0, 0}, {250, 0, 0} };
			std::cout << "size\thash\tchain" << std::endl;
			for (int h = 0; h < 4; h++) {
				int size = testDataTable[h][0];
				//std::cout << "Size: " << size << std::endl;
				HashTable<Student> Hash(size);
				ChainHash<Student> Chain(size);
				//std::cout << "Comparing touches for a table of size " <<size <<":" << std::endl;
				Student studentArr[size];
				//std::cout << (sizeof(studentArr)/sizeof(*studentArr)) << std::endl;
				for (int i = 0; i < 50; i++) {
					Student temp = createRandomStudent();
					studentArr[i] = temp;
					Hash.Insert(studentArr[i]);
					Chain.Insert(studentArr[i]);
				}
				//std::cout << "Student\tHash Touches\tChain Hash Touches" << std::endl;
				for (int i = 0; i < 50; i++) {
					testDataTable[h][1] += Hash.GetItemTouches(studentArr[i]);
					testDataTable[h][2] += Chain.GetItemTouches(studentArr[i]);
					//std::cout << studentArr[i] << "\t\t" << hashTouches << "\t\t" << chainTouches << std::endl;
					
				}
				std::cout << testDataTable[h][0] << "\t" << testDataTable[h][1] << "\t" << testDataTable[h][2] << std::endl;
			}
			
			break;
		}
		case 4: {
			return 0;
		}
		}
	}
}

//size		hash		chain
//50		#			#	


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

	std::getline(std::cin, major);
	//std::cin >> major;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline left in the buffer

	Student temp(firstName, lastName, mNumber, major);
	return temp;
}

Student mNumSearch() {
	int mNumber;
	std::cout << "Please enter the student's mNumber: " << std::endl;
	std::cin >> mNumber;
	Student temp("", "", mNumber, "");
	return temp;
}

Student createRandomStudent() {
	std::string firstNames[] = {"Steve", "Sue", "Mark", "Sarah", "Josh", "Kelly", "Jerry", "Lisa", "Paul", "Rachel"};
	std::string lastNames[] = {"Smith", "Harvey", "North", "Bines", "O'Conner", "Lincoln", "Adams", "Johnson", "Grant", "Trump"};
	std::string majors[] = {"CS", "Biology", "Law", "Art", "Architecture", "Business", "Engineering", "English", "Gamer", "Doctor"};

	int randFName = rand() % 10;
	int randLName = rand() % 10;
	int randMNum = (rand() % 1000000) +10000000;
	int randMJ = rand() % 10;

	Student temp(firstNames[randFName], lastNames[randLName], randMNum, majors[randMJ]);
	return temp;
}