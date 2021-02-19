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
	// only runs on the first iteration
	if (num2->isUnassigned()) { 
		delete num2;
		num2 = this;
	}

	long n = max(num1->getSize(), num2->getSize());
	if (n <= BASE_SIZE) {
		int n1 = stoi(num1->getNum());
		int n2 = stoi(num2->getNum());
		int result = n1 * n2;
		return new LongInt(to_string(result));
	} else {
		num1->adjustLengthsToMatch(num2);
		LongInt** a = num1->getHalves();
		LongInt** b = num2->getHalves();
		LongInt* P1 = karatsuba(a[0], b[0]);
		LongInt* P2 = karatsuba(a[1], b[1]);
		LongInt* P3 = karatsuba(a[0]->add(a[1]), b[0]->add(b[1]));

		// P1*10^n + (P3 - P2 - P1)*10^(n/2) + P2
		LongInt* result = P1->addTrailingZeroes(n)->add(P3->sub(P2)->sub(P1)->addTrailingZeroes(n / 2))->add(P2);
		result->subZeroes();
		delete a, b, P1, P2, P3;
		return result;
	}
}

// returns a new LongInt with extra zeroes
LongInt* LongInt::addTrailingZeroes(int numZeroes) {
	string newNum = num;
	for (int i = 0; i < numZeroes; i++) {
		newNum += '0';
	}
	return new LongInt(newNum);
}

void LongInt::addLeadingZeroes(long numZeroes) {
	for (int i = 0; i < numZeroes; i++) {
		num = '0' + num;
	}
}

// substracts the zeroes from the current object
void LongInt::subZeroes() {
	while (num[0] == '0') {
		num = num.substr(1);
	}
}

LongInt* LongInt::add(LongInt* toAdd) {
	int carry = 0;
	string result = "";
	// ensures that "this" is always the largest number
	if (toAdd->getSize() > getSize()) {
		return toAdd->add(this);
	}

	string num1 = getNum();
	string num2 = toAdd->getNum();
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	for(long i = 0; i < getSize(); i++) {
		int sum = 0;
		if (i < num2.size()) {
			sum = (num1[i] - '0') + (num2[i] - '0') + carry;
		} else {
			sum = (num1[i] - '0') + carry;
		}

		carry = sum / 10;
		result += to_string(sum % 10);
	}
	if (carry > 0) result += to_string(carry);

	reverse(result.begin(), result.end());
	return new LongInt(result);
}

LongInt* LongInt::sub(LongInt* toSub) {
	if (toSub->isEqual(this)) return new LongInt("0");
	int carry = 0;
	string result = "";

	string num1 = getNum();
	string num2 = toSub->getNum();
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	for (int i = 0; i < num1.size(); i++) {
		int diff = 0;
		if (i < num2.size()) {
			diff = (num1[i] - '0') - (num2[i] - '0') - carry;
		} else {
			diff = (num1[i] - '0') - carry;
		}

		if (diff < 0) {
			diff += 10;
			carry = 1;
		} else {
			carry = 0;
		}

		result += to_string(diff);
	}

	int end = result.size() - 1;
	while (result[end] == '0' && end > 0) {
		end--;
	}
	if (end > 0) result = result.substr(0, end + 1); // removing extraneous zeroes
	else result = "0";
	reverse(result.begin(), result.end()); // flipping result back into the right order
	return new LongInt(result);
}

LongInt** LongInt::getHalves() {
	long mid = getSize() / 2;
	LongInt** halves = new LongInt * [2];
	halves[0] = new LongInt(getNum().substr(0, mid));
	halves[1] = new LongInt(getNum().substr(mid, mid));
	return halves;
}

void LongInt::adjustLengthsToMatch(LongInt* num2) {
	if (getSize() > num2->getSize()) {
		num2->addLeadingZeroes(getSize() - num2->getSize());
	} else if(num2->getSize() > getSize()) {
		addLeadingZeroes(num2->getSize() - getSize());
	}

	if (getSize() % 2 == 1) {
		addLeadingZeroes(1);
		num2->addLeadingZeroes(1);
	}
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
