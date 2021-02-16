#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Sort.h"
#include "SortType.h"
#include "Timer.h"
using namespace std;

void Sort::fillArray() {
	delete array;
	array = new int[size];
	srand(time(0));

	for (int i = 0; i < size; i++) {
		array[i] = rand(); 
	}
}

// code for merge method taken from: https://www.interviewbit.com/tutorial/merge-sort-algorithm/
void Sort::merge(int start, int mid, int end) {
	// create a temp array
	int* temp = new int[end - start + 1];

	// crawlers for both intervals and for temp
	int i = start, j = mid + 1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp 
	while (i <= mid && j <= end) {
		if (array[i] <= array[j]) {
			temp[k] = array[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = array[j];
			k += 1; j += 1;
		}
	}

	// add elements left in the first interval 
	while (i <= mid) {
		temp[k] = array[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval 
	while (j <= end) {
		temp[k] = array[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for (i = start; i <= end; i += 1) {
		array[i] = temp[i - start];
	}

	delete temp;
}

void Sort::isSorted() {
	for (int i = 1; i < size; i++) {
		if (array[i] < array[i - 1]) {
			cout << getTypePrettyName() << " of size " << size << " failed." << endl;
		}
	}
}

void Sort::mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}

void Sort::bubbleSort() {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void Sort::printResult(double totalTime) {
	cout << getTypePrettyName() << " of size " << size << ": " << totalTime / SAMPLE_SIZE << " seconds" << endl;
}

std::string Sort::getTypePrettyName() {
	return (sortType == Type::BUBBLE) ? "Bubble sort" : "Merge sort";
}

Sort::Sort(Type sortType) {
	this->sortType = sortType;
	this->array = new int[size];
}

void Sort::sort() {
	double totalTime = 0;

	for (int i = 0; i < SAMPLE_SIZE; i++) {
		Timer timer;
		this->fillArray();

		if (sortType == Type::BUBBLE) {
			timer.start();
			bubbleSort();
			timer.stop();
		}
		else {
			timer.start();
			mergeSort(0, size - 1);
			timer.stop();
		}
		isSorted();
		totalTime += timer.getElapsedTimeInSec();
	}

	printResult(totalTime);
}

void Sort::setSize(int size) {
	this->size = size;
}
