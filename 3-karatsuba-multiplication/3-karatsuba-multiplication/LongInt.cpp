#include "LongInt.h"
#include <iostream>
#include <string>
using namespace std;

LongInt::LongInt(string num) {
	this->num = num;
}

LongInt LongInt::mult(LongInt factor) {
	// num is on bottom, factor on top
	for (int i = num.size() - 1; i >= 0; i--) {
		for (int j = factor.getSize() - 1; j >= 0; j--) {
			// add num[j] * factor[
			// TODO: implement grade school algorithm
		}
	}
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
