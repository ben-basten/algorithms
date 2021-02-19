#pragma once
#include <string>

class LongInt {
private:
	std::string num;
	//FOR KARATSUBA
	const int BASE_SIZE = 2;

	LongInt* addTrailingZeroes(int numZeroes);
	void addLeadingZeroes(long numZeroes);
	void subZeroes();
	LongInt* add(LongInt* toAdd);
	LongInt* sub(LongInt* toSub);
public:
	LongInt(std::string num = "-1");
	LongInt* mult(LongInt* toMult);
	LongInt* karatsuba(LongInt* num1, LongInt* num2 = new LongInt());
	LongInt** getHalves();
	void adjustLengthsToMatch(LongInt* num2);
	bool isEqual(LongInt* toCompare);
	bool isUnassigned();
	std::string getNum();
	long getSize();
	void print();
};