#pragma once
#include <string>

class LongInt {
private:
	std::string num;

	void addZeroes(int n);
	void subZeroes(int n);
	//LongInt add(LongInt toAdd);
	//LongInt sub(LongInt toSub);
public:
	LongInt(std::string num);
	LongInt mult(LongInt toMult);
	bool isEqual(LongInt toCompare);
	std::string getNum();
	long getSize();
	void print();
};