#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

namespace SortAlgo {
	// 选择排序 O(n^2)
	template<typename T>
	void SelectSort(T arr[], int sz) {
		for (int i = 0; i < sz; i++) {
			int pos = i;
			for (int j = i + 1; j < sz; j++) {
				if (arr[j] < arr[pos]) {
					pos = j;
				}
			}
			swap(arr[i], arr[pos]);
		}
	}

	// 冒泡排序 O(n^2)
	template<typename T>
	void BubbleSort(T arr[], int sz) {
		int pos;
		do 
		{
			pos = 0;
			for (int i = 1; i < sz; i++) {
				if (arr[i - 1] > arr[i]) {
					swap(arr[i - 1], arr[i]);
					pos = i; // 记录下交换的位置，下次循环后面的数据不再扫描
				}
			}
			sz = pos;
		} while (pos > 0);
	}


	// 插入排序 O(n^2)
	// 跟选择排序的区别：可以通过 arr[j - 1] > e 提前终止数据的扫描
	// 适用于小中规模或者有序性高的数据排序
	template<typename T>
	void InsertSort(T arr[], int sz) {
		for (int i = 1; i < sz; i++) {
			T e = arr[i];
			int j = i;
			for (; j > 0 && arr[j - 1] > e; j--) {
				arr[j] = arr[j - 1];
			}
			arr[j] = e;
		}
	}

	template<typename T>
	void insertSort(T arr[], int l, int r) {
		for (int i = l + 1; i <= r; i++) {
			T e = arr[i];
			int j = i;
			for (; j > l && arr[j - 1] > e; j--) {
				arr[j] = arr[j - 1];
			}
			arr[j] = e;
		}
	}

	// 希尔排序 O(n^(3/2))
	// 插入排序的升级版，适用于大规模数据的排序，思想就是将大规模数据进行分段插入排序，直至分段到1
	template<typename T>
	void ShellSort(T arr[], int sz) {
		int seg = 1;
		while (seg < sz / 3) {
			seg = seg * 3 + 1;
		}

		// 每次分段排序后，有序性都会提高，故而整体的性能非常高
		while (seg >= 1)
		{
			for (int i = seg; i < sz; i++) {
				// arr[i], arr[i - seg], arr[i - 2 * seg]...进行插入排序
				T e = arr[i];
				int j = i;
				for (; j >= seg && arr[j - seg] > e; j -= seg) {
					arr[j] = arr[j - seg];
				}
				arr[j] = e;
			}
			seg /= 3;
		}
	}

	// 归并排序 O(logn)
	// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
	template<typename T>
	void merge(T arr[], int l, int m, int r) {
		T* tmp = new T[r - l + 1];
		for (int i = l; i <= r; i++) {
			tmp[i - l] = arr[i];
		}
		
		int i = l, j = m + 1;
		for (int k = l; k <= r; k++) {
			if (i > m) { // 如果左半部分元素已经全部处理完毕
				arr[k] = tmp[j - l];
				j++;
			}
			else if (j > r) { // 如果右半部分元素已经全部处理完毕
				arr[k] = tmp[i - l];
				i++;
			}
			else if (tmp[i - l] < tmp[j - l]) { // 左半部分所指元素 < 右半部分所指元素
				arr[k] = tmp[i - l];
				i++;
			}
			else { // 左半部分所指元素 >= 右半部分所指元素
				arr[k] = tmp[j - l];
				j++;
			}
		}
		delete[] tmp;
	}

	template<typename T>
	void mergeSort(T arr[], int l, int r) {
		if (r - l <= 15) { // 当元素个数小于等于15时，调用插入排序提高性能
			insertSort(arr, l, r);
			return;
		}

		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		if (arr[m] > arr[m + 1]) { // 如果 arr[m] <= arr[m + 1] 则表示arr已经有序，不需要进行归并了
			merge(arr, l, m, r);
		}
	}

	template<typename T>
	void MergeSort(T arr[], int sz) { // 默认的归并排序是自顶向下的归并
		mergeSort(arr, 0, sz - 1);
	}

	template<typename T>
	void MergeSortBU(T arr[], int sz) { // 自底向上的归并排序
		for (int i = 0; i < sz; i += 16) {
			insertSort(arr, i, min(i + 15, sz - 1));
		}
		for (int i = 16; i < sz; i += i) {
			for (int j = 0; j < sz - i; j += i + i) {
				if (arr[j + i - 1] > arr[j + i]) {
					// 对arr[j, j+i-1]和arr[j+i, j+i+i-1]进行归并
					merge(arr, j, j + i - 1, min(j + i + i - 1, sz - 1));
				}
			}
		}
	}

	// 快速排序 O(logn)
	template<typename T>
	void QuickSort(T a[], int n)
	{
		if (n <= 1) {
			return;
		}
		if (n == 2) { 
			if (a[0] > a[1]) {
				swap(a[0], a[1]); 
				return;
			}
		}
		swap(a[n / 2], a[0]);//标杆与第一个交换
		int pivot = a[0];//标杆
		T* L = a + 1;
		T* R = a + n - 1;
		while (L < R) {
			while (L < R && *L < pivot) ++L;//从左向右找不小的
			while (a < R && *R >= pivot) --R;//从右向左找小的
			if (L < R) swap(*L, *R);//未相遇就交换
		}
		swap(a[0], *R);//标杆跟从右向左找到的数据交换
		QuickSort(a, R - a);//对左边这组数据排序
		QuickSort(R + 1, n - (R - a) - 1);//对右边这组数据排序
	}

	template<typename T>
	class MaxHeap {
	private:
		T* data; // 二叉堆
		int count;

		void shiftUp(int i) {
			while (i > 1 && data[i] < data[i / 2]) {
				swap(data[i], data[i / 2]);
				i /= 2;
			}
		}

		void shiftDown(int i) {
			while (i * 2 <= count) { // 有子节点
				T v = data[i * 2];
				int j = i * 2;
				if (data[i * 2] < data[i * 2 + 1]) {
					j += 1;
				}
				swap(data[i], data[j]);
				i = j;
			}
		}

	public:
		MaxHeap(T arr[], int sz) {
			data = new T[sz + 1];
			count = sz;
			for (int i = 0; i < sz; i++) {
				data[i + 1] = arr[i];
			}
			for (int i = count / 2; i > 1; i--) {
				shiftDown(i);
			}
		}

		~MaxHeap() {
			delete[] data;
		}

		void Push(T v) {
			data[count + 1] = v;
			count++;
			shiftUp(count);
		}

		T Pop() {
			T v = data[1];
			data[1] = data[count];
			count--;
			shiftDown(1);
			return v;
		}
	};

	// 堆排序 O(nlogn)
	template<typename T>
	void HeapSort(T arr[], int sz) {
		MaxHeap<T> mh = MaxHeap<T>(arr, sz);
		for (int i = sz - 1; i >= 0; i--) {
			arr[i] = mh.Pop();
		}
	}
}

#endif // SORT_H