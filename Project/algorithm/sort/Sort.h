#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

namespace SortAlgo {
	// ѡ������ O(n^2)
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

	// ð������ O(n^2)
	template<typename T>
	void BubbleSort(T arr[], int sz) {
		int pos;
		do 
		{
			pos = 0;
			for (int i = 1; i < sz; i++) {
				if (arr[i - 1] > arr[i]) {
					swap(arr[i - 1], arr[i]);
					pos = i; // ��¼�½�����λ�ã��´�ѭ����������ݲ���ɨ��
				}
			}
			sz = pos;
		} while (pos > 0);
	}


	// �������� O(n^2)
	// ��ѡ����������𣺿���ͨ�� arr[j - 1] > e ��ǰ��ֹ���ݵ�ɨ��
	// ������С�й�ģ���������Ըߵ���������
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

	// ϣ������ O(n^(3/2))
	// ��������������棬�����ڴ��ģ���ݵ�����˼����ǽ����ģ���ݽ��зֶβ�������ֱ���ֶε�1
	template<typename T>
	void ShellSort(T arr[], int sz) {
		int seg = 1;
		while (seg < sz / 3) {
			seg = seg * 3 + 1;
		}

		// ÿ�ηֶ�����������Զ�����ߣ��ʶ���������ܷǳ���
		while (seg >= 1)
		{
			for (int i = seg; i < sz; i++) {
				// arr[i], arr[i - seg], arr[i - 2 * seg]...���в�������
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

	// �鲢���� O(logn)
	// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
	template<typename T>
	void merge(T arr[], int l, int m, int r) {
		T* tmp = new T[r - l + 1];
		for (int i = l; i <= r; i++) {
			tmp[i - l] = arr[i];
		}
		
		int i = l, j = m + 1;
		for (int k = l; k <= r; k++) {
			if (i > m) { // �����벿��Ԫ���Ѿ�ȫ���������
				arr[k] = tmp[j - l];
				j++;
			}
			else if (j > r) { // ����Ұ벿��Ԫ���Ѿ�ȫ���������
				arr[k] = tmp[i - l];
				i++;
			}
			else if (tmp[i - l] < tmp[j - l]) { // ��벿����ָԪ�� < �Ұ벿����ָԪ��
				arr[k] = tmp[i - l];
				i++;
			}
			else { // ��벿����ָԪ�� >= �Ұ벿����ָԪ��
				arr[k] = tmp[j - l];
				j++;
			}
		}
		delete[] tmp;
	}

	template<typename T>
	void mergeSort(T arr[], int l, int r) {
		if (r - l <= 15) { // ��Ԫ�ظ���С�ڵ���15ʱ�����ò��������������
			insertSort(arr, l, r);
			return;
		}

		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		if (arr[m] > arr[m + 1]) { // ��� arr[m] <= arr[m + 1] ���ʾarr�Ѿ����򣬲���Ҫ���й鲢��
			merge(arr, l, m, r);
		}
	}

	template<typename T>
	void MergeSort(T arr[], int sz) { // Ĭ�ϵĹ鲢�������Զ����µĹ鲢
		mergeSort(arr, 0, sz - 1);
	}

	template<typename T>
	void MergeSortBU(T arr[], int sz) { // �Ե����ϵĹ鲢����
		for (int i = 0; i < sz; i += 16) {
			insertSort(arr, i, min(i + 15, sz - 1));
		}
		for (int i = 16; i < sz; i += i) {
			for (int j = 0; j < sz - i; j += i + i) {
				if (arr[j + i - 1] > arr[j + i]) {
					// ��arr[j, j+i-1]��arr[j+i, j+i+i-1]���й鲢
					merge(arr, j, j + i - 1, min(j + i + i - 1, sz - 1));
				}
			}
		}
	}

	// �������� O(logn)
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
		swap(a[n / 2], a[0]);//������һ������
		int pivot = a[0];//���
		T* L = a + 1;
		T* R = a + n - 1;
		while (L < R) {
			while (L < R && *L < pivot) ++L;//���������Ҳ�С��
			while (a < R && *R >= pivot) --R;//����������С��
			if (L < R) swap(*L, *R);//δ�����ͽ���
		}
		swap(a[0], *R);//��˸����������ҵ������ݽ���
		QuickSort(a, R - a);//�����������������
		QuickSort(R + 1, n - (R - a) - 1);//���ұ�������������
	}

	template<typename T>
	class MaxHeap {
	private:
		T* data; // �����
		int count;

		void shiftUp(int i) {
			while (i > 1 && data[i] < data[i / 2]) {
				swap(data[i], data[i / 2]);
				i /= 2;
			}
		}

		void shiftDown(int i) {
			while (i * 2 <= count) { // ���ӽڵ�
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

	// ������ O(nlogn)
	template<typename T>
	void HeapSort(T arr[], int sz) {
		MaxHeap<T> mh = MaxHeap<T>(arr, sz);
		for (int i = sz - 1; i >= 0; i--) {
			arr[i] = mh.Pop();
		}
	}
}

#endif // SORT_H