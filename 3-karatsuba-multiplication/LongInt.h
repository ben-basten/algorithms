#pragma once
#include <string>

class LongInt {
private:
	std::string num;
	//FOR KARATSUBA
	const int BASE_SIZE = 5;

	LongInt* addZeroes(int numZeroes);
	void subZeroes(int n);
	LongInt* add(LongInt* toAdd);
	LongInt* sub(LongInt* toSub);
public:
	LongInt(std::string num = "-1");
	LongInt* mult(LongInt* toMult);
	LongInt* karatsuba(LongInt* num1, LongInt* num2 = new LongInt());
	LongInt** getHalves();
	bool isEqual(LongInt* toCompare);
	bool isUnassigned();
	std::string getNum();
	long getSize();
	void print();
};