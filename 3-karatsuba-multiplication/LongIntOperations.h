#pragma once
#include "LongInt.h"
#include <string>

class LongIntOperations {
private:
	LongInt* num1;
	LongInt* num2;
public:
	LongIntOperations(std::string num1, std::string num2);
	~LongIntOperations();
	LongInt* mult(); // grade school method
	LongInt* karatsuba();
};