#ifndef __STUDENT__
#define __STUDENT__

#include <iostream>

class Student {
	private:
		std::string firstName;
		std::string lastName;
		std::string mNumber;
		std::string major;

	public:
		Student() : firstName(" "), lastName(" "), mNumber(" "), major(" ") {};
        Student(std::string fN,std::string lN, std::string mN, std::string mjr) : firstName(fN), lastName(lN), mNumber(mN), major(mjr) {};


        bool operator>(const Student &right) { return this->mNumber > right.mNumber; }
        bool operator<(const Student &right) { return this->mNumber < right.mNumber; }
        bool operator==(const Student &right) { return this->mNumber == right.mNumber; }
        bool operator!=(const Student &right) { return this->mNumber != right.mNumber; }
		
};

#endif
