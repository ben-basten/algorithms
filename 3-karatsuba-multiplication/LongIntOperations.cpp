#include "LongIntOperations.h"
#include "LongInt.h"
#include <string>
using namespace std;

LongInt LongIntOperations::karatsuba(LongInt num1, LongInt num2) {
	return LongInt("-1");
}

LongIntOperations::LongIntOperations(string str1, string str2) : num1(str1), num2(str2) { }

LongInt LongIntOperations::mult() {
	return num1.mult(num2);
}

LongInt LongIntOperations::karatsuba() {
	return karatsuba(num1, num2);
}
