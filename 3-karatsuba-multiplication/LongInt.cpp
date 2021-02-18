#include "LongInt.h"
#include <iostream>
#include <string>
using namespace std;

LongInt::LongInt(string num) {
	this->num = num;
}

LongInt* LongInt::mult(LongInt* factor) {
	if (getNum() == "0" || factor->getNum() == "0") return new LongInt("0");

	int maxSize = getSize() + factor->getSize();
	int* columns = new int[maxSize]; // columns of the multiplication sums
	for (int i = 0; i < maxSize; i++) {
		columns[i] = 0;
	}

	int pos1 = getSize() - 1;
	int pos2 = factor->getSize();

	for (int i = getSize() - 1; i >= 0; i--) {
		int carry = 0;
		int bottomDigit = getNum()[i] - '0'; // using ascii to convert into an int

		pos2 = factor->getSize();

		for (int j = factor->getSize() - 1; j >= 0; j--) {
			int topDigit = factor->getNum()[j] - '0';
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
	return new LongInt(res);
}

LongInt* LongInt::karatsuba(LongInt* num1, LongInt* num2) {
	if (num2->isUnassigned()) { // checks if this is the first iteration through karatsuba
		delete num2;
		num2 = this;
	}

	long maxSize = max(num1->getSize(), num2->getSize());
	if (maxSize <= BASE_SIZE) {
		int n1 = stoi(num1->getNum());
		int n2 = stoi(num2->getNum());
		int result = n1 * n2;
		return new LongInt(to_string(result));
	} else {
		LongInt** a = num1->getHalves();
		LongInt** b = num2->getHalves();
		LongInt* P1 = karatsuba(a[0], b[0]);
		LongInt* P2 = karatsuba(a[1], b[1]);
		LongInt* P3 = karatsuba(a[0]->add(a[1]), b[0]->add(b[1]));

		// P1*10^n + (P3 - P2 - P1)*10^(n/2) + P2
		return P1->addZeroes(n)->add(P3->sub(P2)->sub(P1))->addZeroes(n/2)->add(P2);
	}
}

LongInt* LongInt::addZeroes(int n) {
	return new LongInt();
}

void LongInt::subZeroes(int n) {

}

LongInt* LongInt::add(LongInt* toAdd) {
	return new LongInt();
}

LongInt* LongInt::sub(LongInt* toSub) {
	return new LongInt();
}

LongInt** LongInt::getHalves() {
	long mid = getSize() / 2;
	LongInt* halves[2] = { new LongInt(getNum().substr(0, mid)), new LongInt(getNum().substr(mid, mid)) };
	return halves;
}

bool LongInt::isEqual(LongInt* toCompare) {
	return num == toCompare->getNum();
}

bool LongInt::isUnassigned() {
	return getNum() == "-1";
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
