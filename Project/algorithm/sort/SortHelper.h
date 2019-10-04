#ifndef SORT_HELPER_H
#define SORT_HELPER_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

namespace SortHelper {
	// ����һ����СΪsz��������飬Ԫ�ش�С��Χ[min, max]
	template<typename T>
	T* genRandArr(int sz, T min, T max) {
		srand(time(NULL));
		T* arr = new T[sz];
		for (int i = 0; i < sz; i++) {
			arr[i] = rand() % (max - min + 1) + min;
		}
		return arr;
	}

	// ����һ���ӽ����������
	int* genNearlySortedArr(int sz, int swapTimes);

	// ����һ������
	template<typename T>
	T* copyArr(T arr[], int sz) {
		T* ret = new T[sz];
		copy(arr, arr + sz, ret);
		return ret;
	}

	// ��ӡһ������
	template<typename T>
	void Print(T arr[], int sz) {
		for (int i = 0; i < sz; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	// ���ܲ���
	void test(string sortName, void(*func)(int[], int), int arr[], int sz);
}

#endif // SORT_HELPER_H