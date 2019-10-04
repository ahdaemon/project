#include "SortHelper.h"

namespace SortHelper {
	int* genNearlySortedArr(int sz, int swapTimes) {
		int* arr = new int[sz];
		for (int i = 0; i < sz; i++) {
			arr[i] = i;
		}
		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++) {
			int pos1 = rand() % sz;
			int pos2 = rand() % sz;
			swap(arr[pos1], arr[pos2]);
		}
		return arr;
	}

	void test(string sortName, void(*func)(int[], int), int arr[], int sz) {
		clock_t beg = clock();
		func(arr, sz);
		clock_t end = clock();
		cout << sortName << " use time:" << (float)(end - beg) / CLOCKS_PER_SEC <<  "s" << endl;
	}
}