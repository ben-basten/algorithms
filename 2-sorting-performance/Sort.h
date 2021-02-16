#pragma once
#include "SortType.h"
#include <string>

class Sort {
private:
	const int SAMPLE_SIZE = 4;
	int* array;
	int size = 10;
	Type sortType;

	void fillArray();
	void merge(int left, int mid, int right);
	void isSorted();
	void mergeSort(int left, int right);
	void bubbleSort();
	void printResult(double totalTime);
	std::string getTypePrettyName();
public:
	Sort(Type sortType);
	void sort();
	void setSize(int size);
};