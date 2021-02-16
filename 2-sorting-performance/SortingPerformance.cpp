#include "Sort.h"
#include "SortType.h"
using namespace std;

int n[7] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000 };

int main(int argc, char** argv) {
	Sort bubbleSort = Sort(Type::BUBBLE);
	Sort mergeSort = Sort(Type::MERGE);
	for (int i = 0; i < 7; i++) {
		bubbleSort.setSize(n[i]);
		mergeSort.setSize(n[i]);
		bubbleSort.sort();
		mergeSort.sort();
	}
}