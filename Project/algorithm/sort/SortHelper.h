#ifndef SORT_HELPER_H
#define SORT_HELPER_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

namespace SortHelper {
	// 生成一个大小为sz的随机数组，元素大小范围[min, max]
	template<typename T>
	T* genRandArr(int sz, T min, T max) {
		srand(time(NULL));
		T* arr = new T[sz];
		for (int i = 0; i < sz; i++) {
			arr[i] = rand() % (max - min + 1) + min;
		}
		return arr;
	}

	// 生成一个接近有序的数组
	int* genNearlySortedArr(int sz, int swapTimes);

	// 拷贝一个数组
	template<typename T>
	T* copyArr(T arr[], int sz) {
		T* ret = new T[sz];
		copy(arr, arr + sz, ret);
		return ret;
	}

	// 打印一个数组
	template<typename T>
	void Print(T arr[], int sz) {
		for (int i = 0; i < sz; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	// 性能测试
	void test(string sortName, void(*func)(int[], int), int arr[], int sz);
}

#endif // SORT_HELPER_H