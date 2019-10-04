#include <iostream>
#include "algorithm/sort/Sort.h"
#include "algorithm/sort/SortHelper.h"
using namespace std;

int main() {
	int sz = 10000;
	int* arr = SortHelper::genRandArr(sz, 0, sz);
	int* arr1 = SortHelper::copyArr(arr, sz);

	int swapTimes = 100;
	int* nearlyArr = SortHelper::genNearlySortedArr(sz, swapTimes);
	int* nearlyArr1 = SortHelper::copyArr(nearlyArr, sz);

	//SortHelper::test("SelectSort normal", SortAlgo::SelectSort, arr, sz);
	//SortHelper::test("SelectSort nearly", SortAlgo::SelectSort, nearlyArr, sz);
	//SortHelper::test("InsertSort normal", SortAlgo::InsertSort, nearlyArr, sz);
	//SortHelper::test("ShellSort normal", SortAlgo::ShellSort, arr, sz);
	//SortHelper::test("MergeSort normal", SortAlgo::MergeSort, nearlyArr, sz);
	//SortHelper::test("MergeSortBU normal", SortAlgo::MergeSortBU, arr, sz);
	SortHelper::test("QuickSort normal", SortAlgo::QuickSort, arr, sz);
	SortHelper::test("HeapSort normal", SortAlgo::HeapSort, arr, sz);
	//SortHelper::Print(arr, sz);

	//SortHelper::test("BubbleSort", SortAlgo::BubbleSort, arr1, sz);
	//SortHelper::Print(arr1, sz);

	delete[] arr;
	delete[] arr1;
	delete[] nearlyArr;
	delete[] nearlyArr1;

	cin.get();
	return 0;
}