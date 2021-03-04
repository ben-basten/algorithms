#include <iostream>
#include <string>
#include "LongIntOperations.h"
using namespace std; 

int main(int argc, char** argv) {
	cout << "Enter an integer." << endl;
	string num1, num2;
	cin >> num1;
	cout << "Enter another integer." << endl;
	cin >> num2;

	LongIntOperations ops = LongIntOperations(num1, num2);
	LongInt* gradeSchool = ops.mult();
	cout << "grade school: ";
	gradeSchool->print();
	LongInt* karatsuba = ops.karatsuba();
	cout << "karatsuba:    ";
	karatsuba->print();

	string result = gradeSchool->isEqual(karatsuba) ? "Grade school matches Karatsuba!" : "An error occurred computing the multiplication.";
	cout << result << endl;

	delete karatsuba, gradeSchool;
}