#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class VectorList {

public:

	void MainFunc() {
		cout << "Elements amount: ";
		cin >> size;
		cout << "Sort type, from largest to smallest(0), from smallest to largest(1): ";
		cin >> typeSort;
		cout << "----------------" << endl;

		cout << "Vector: " << endl;
		random(size);
		printArray(size);
		cout << "insertionSort(): " << endl;
		insertionSort(size, typeSort);
		printArray(size);
		cout << "----------------" << endl;
		myVector.clear();
		cout << "*Delete*" << endl;
		cout << "----------------" << endl;


		cout << "Vector: " << endl;
		random(size);
		printArray(size);
		cout << "quickSort(): " << endl;
		quickSort(0, size - 1, typeSort);
		printArray(size);
		cout << "----------------" << endl;
		myVector.clear();
		cout << "*Delete*" << endl;
		cout << "----------------" << endl;


		cout << "Vector: " << endl;
		random(size);
		printArray(size);
		cout << "mergeSort(): " << endl;
		mergeSort(0, size - 1, typeSort);
		printArray(size);
		cout << "----------------" << endl;
		myVector.clear();
		cout << "*Delete*" << endl;
		cout << "----------------" << endl;

	}

private:

	vector<int> myVector;
	int size;
	bool typeSort;

	void random(int size) {
		for (int i = 0; i < size; i++) {
			myVector.push_back(rand() % 100);
		}
	}

	void insertionSort(int size, bool typeSort) {
		int i, key, j;
		for (i = 1; i < size; i++)
		{
			key = myVector[i];
			j = i - 1;
			if (typeSort == 0) {
				while (j >= 0 && myVector[j] < key)
				{
					myVector[j + 1] = myVector[j];
					j = j - 1;
				}
			}
			else {
				while (j >= 0 && myVector[j] > key)
				{
					myVector[j + 1] = myVector[j];
					j = j - 1;
				}
			}
			myVector[j + 1] = key;
		}
	}

	int partitionScheme0(int low, int high)
	{
		int pivot = myVector[low];
		int i = (high + 1);

		for (int j = high; j >= low + 1; j--)
		{
			if (myVector[j] <= pivot)
			{
				i--;
				swap(myVector[i], myVector[j]);
			}
		}
		swap(myVector[i - 1], myVector[low]);
		return (i - 1);
	}

	int partitionScheme1(int low, int high)
	{
		int pivot = myVector[high];
		int i = (low - 1);

		for (int j = low; j < high; j++)
		{
			if (myVector[j] <= pivot)
			{
				i++;
				swap(myVector[i], myVector[j]);
			}
		}
		swap(myVector[i + 1], myVector[high]);
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
				if (myVector[i] > myVector[j]) {
					c[k] = myVector[i];
					k++;
					i++;
				}
				else {
					c[k] = myVector[j];
					k++;
					j++;
				}
			}
		}
		else {
			while (i <= mid && j <= high) {
				if (myVector[i] < myVector[j]) {
					c[k] = myVector[i];
					k++;
					i++;
				}
				else {
					c[k] = myVector[j];
					k++;
					j++;
				}
			}
		}
		while (i <= mid) {
			c[k] = myVector[i];
			k++;
			i++;
		}
		while (j <= high) {
			c[k] = myVector[j];
			k++;
			j++;
		}
		for (i = low; i < k; i++) {
			myVector[i] = c[i];
		}
	}

	void printArray(int size) {
		for (int i = 0; i < size; i++)
			cout << myVector[i] << " ";
		cout << endl;
	}


};