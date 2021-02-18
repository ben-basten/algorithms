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

	/*LongInt* uno = new LongInt(num1);
	LongInt* dos = new LongInt(num2);
	uno->add(dos)->print();*/
	
	LongIntOperations ops = LongIntOperations(num1, num2);
	LongInt* gradeSchool = ops.mult();
	cout << "grade school: ";
	gradeSchool->print(); // TODO: remove this
	LongInt* karatsuba = ops.karatsuba();
	cout << "karatsuba: ";
	karatsuba->print();   // TODO: remove this

	string result = gradeSchool->isEqual(karatsuba) ? "Grade school matches Karatsuba!" : "An error occurred computing the multiplication.";
	cout << result << endl;

	delete karatsuba, gradeSchool;
}