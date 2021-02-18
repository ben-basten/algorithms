#include "LongIntOperations.h"
#include "LongInt.h"
#include <string>
using namespace std;

LongIntOperations::LongIntOperations(string str1, string str2) { 
	num1 = new LongInt(str1);
	num2 = new LongInt(str2);
}

LongIntOperations::~LongIntOperations() {
	delete num1, num2;
}

LongInt* LongIntOperations::mult() {
	return num1->mult(num2);
}

LongInt* LongIntOperations::karatsuba() {
	return num1->karatsuba(num2);
}
