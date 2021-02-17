#include "LongInt.h"
#include <iostream>
#include <string>
using namespace std;

LongInt::LongInt(string num) {
	this->num = num;
}

LongInt LongInt::mult(LongInt factor) {
	if (getNum() == "0" || factor.getNum() == "0") return LongInt("0");

	int maxSize = getSize() + factor.getSize();
	int* columns = new int[maxSize]; // columns of the multiplication sums
	for (int i = 0; i < maxSize; i++) {
		columns[i] = 0;
	}

	int pos1 = getSize() - 1;
	int pos2 = factor.getSize();

	for (int i = getSize() - 1; i >= 0; i--) {
		int carry = 0;
		int bottomDigit = getNum()[i] - '0'; // using ascii to convert into an int

		pos2 = factor.getSize();

		for (int j = factor.getSize() - 1; j >= 0; j--) {
			int topDigit = factor.getNum()[j] - '0';
			int columnSum = bottomDigit * topDigit + carry + columns[pos1 + pos2];

			carry = columnSum / 10; 
			columnSum = columnSum % 10;

			columns[pos1 + pos2] = columnSum;

			pos2--;
		}

		columns[pos1 + pos2] += carry;
		pos1--;
	}

	string res = "";
	for (int i = 0; i < maxSize; i++) {
		res += to_string(columns[i]);
	}

	// possible there's an extra 0 at the beginning, remove if so
	if (res[0] == '0') res = res.substr(1);

	delete[] columns;
	return LongInt(res);
}

void LongInt::addZeroes(int n) {

}

void LongInt::subZeroes(int n) {

}

bool LongInt::isEqual(LongInt toCompare) {
	return num == toCompare.getNum();
}

std::string LongInt::getNum() {
	return num;
}

long LongInt::getSize() {
	return num.size();
}

void LongInt::print() {
	cout << num << endl;
}
