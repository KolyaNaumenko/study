#include <stdlib.h>
#include <iostream>

using namespace std;
class ArrayList
{

public:

	void MainFunc() {
		cout << "Elements amount: ";
		cin >> size;
		cout << "Sort type, from largest to smallest(0), from smallest to largest(1): ";
		cin >> typeSort;
		cout << "----------------" << endl;

		cout << "Array: " << endl;
		random(size);
		printArray(size);
		cout << "insertionSort(): " << endl;
		insertionSort(size, typeSort);
		printArray(size);
		cout << "----------------" << endl;

		cout << "Array: " << endl;
		random(size);
		printArray(size);
		cout << "quickSort(): " << endl;
		quickSort(0, size - 1, typeSort);
		printArray(size);
		cout << "----------------" << endl;

		cout << "Array: " << endl;
		random(size);
		printArray(size);
		cout << "mergeSort(): " << endl;
		mergeSort(0, size - 1, typeSort);
		printArray(size);
		cout << "----------------" << endl;
	}

private:

	int arr[100];
	int size;
	bool typeSort;

	void random(int size) {
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 100;
		}
	}

	void insertionSort(int size, bool typeSort) {
		int i, key, j;
		for (i = 1; i < size; i++)
		{
			key = arr[i];
			j = i - 1;
			if (typeSort == 0) {
				while (j >= 0 && arr[j] < key)
				{
					arr[j + 1] = arr[j];
					j = j - 1;
				}
			}
			else {
				while (j >= 0 && arr[j] > key)
				{
					arr[j + 1] = arr[j];
					j = j - 1;
				}
			}
			arr[j + 1] = key;
		}
	}

	int partitionScheme0(int low, int high)
	{
		int pivot = arr[low];
		int i = (high + 1);

		for (int j = high; j >= low + 1; j--)
		{
			if (arr[j] <= pivot)
			{
				i--;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i - 1], arr[low]);
		return (i - 1);
	}

	int partitionScheme1(int low, int high)
	{
		int pivot = arr[high];
		int i = (low - 1);

		for (int j = low; j < high; j++)
		{
			if (arr[j] <= pivot)
			{
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[high]);
		return (i + 1);
	}

	void quickSort(int low, int high, bool typeSort)
	{
		if (low < high)
		{
			if (typeSort == 0) {
				int pi = partitionScheme0(low, high);

				quickSort(low, pi - 1, typeSort);
				quickSort(pi + 1, high, typeSort);
			}
			else {
				int pi = partitionScheme1(low, high);

				quickSort(low, pi - 1, typeSort);
				quickSort(pi + 1, high, typeSort);
			}
		}
	}

	void mergeSort(int low, int high, bool typeSort)
	{
		int mid;
		if (low < high) {
			mid = (low + high) / 2;
			mergeSort(low, mid, typeSort);
			mergeSort(mid + 1, high, typeSort);
			merge(low, high, mid, typeSort);
		}
	}

	void merge(int low, int high, int mid, bool typeSort)
	{
		int i, j, k, c[50];
		i = low;
		k = low;
		j = mid + 1;
		if (typeSort == 0) {
			while (i <= mid && j <= high) {
				if (arr[i] > arr[j]) {
					c[k] = arr[i];
					k++;
					i++;
				}
				else {
					c[k] = arr[j];
					k++;
					j++;
				}
			}
		}
		else {
			while (i <= mid && j <= high) {
				if (arr[i] < arr[j]) {
					c[k] = arr[i];
					k++;
					i++;
				}
				else {
					c[k] = arr[j];
					k++;
					j++;
				}
			}
		}
		while (i <= mid) {
			c[k] = arr[i];
			k++;
			i++;
		}
		while (j <= high) {
			c[k] = arr[j];
			k++;
			j++;
		}
		for (i = low; i < k; i++) {
			arr[i] = c[i];
		}
	}

	void printArray(int size) {
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};