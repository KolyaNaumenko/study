#include <stdlib.h>
#include <iostream>

using namespace std;

template<typename L>
class List {
public:

	List();
	~List();

	void add(L data);
	int length() { return Size; }
	L& operator[](const int index);
	void del(const int index);
	void random(int size);
	void MainFunc();
	void insertionSort(int size, bool typeSort);
	int partitionScheme0(int low, int high);
	int partitionScheme1(int low, int high);
	void quickSort(int low, int high, bool typeSort);
	void mergeSort(int low, int high, bool typeSort);
	void merge(int low, int high, int mid, bool typeSort);

	bool typeSort;
	int size;

private:

	template<typename L>
	class Node {
	public:
		Node* pNext;
		L data;

		Node(L data = L(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<L>* head;
};

template<typename L>
List<L>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename L>
List<L>::~List()
{
}

template<typename L>
void List<L>::add(L data)
{
	if (head == nullptr) {
		head = new Node<L>(data);

	}
	else {
		Node<L>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<L>(data);
	}
	Size++;
}

template<typename L>
L& List<L>::operator[](const int index)
{
	int counter = 0;
	Node<L>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}


template<typename L>
void List<L>::del(int index)
{
	if (index == 0)
	{
		Node<L>* temp = head;

		head = head->pNext;

		delete temp;

		Size--;
	}
	else
	{
		Node<L>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<L>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename L>
void List<L>::random(int size) {
	for (int i = 0; i < size; i++) {
		add(rand() % 100);
	}
}

template<typename L>
void List<L>::MainFunc() {
	cout << "Elements amount: ";
	cin >> size;
	cout << "Sort type, from largest to smallest(0), from smallest to largest(1): ";
	cin >> typeSort;
	cout << "----------------" << endl;

	cout << "List: " << endl;
	random(size);
	for (int i = 0; i < length(); i++) {
		cout << operator[](i) << " ";
	}
	cout << endl;
	cout << "insertionSort(): " << endl;
	insertionSort(size, typeSort);
	for (int i = 0; i < length(); i++) {
		cout << operator[](i) << " ";
	}
	cout << endl;
	cout << "----------------" << endl;
	for (int i = size - 1; i >= 0; i--) {
		del(i);
	}
	cout << "*Delete*" << endl;
	cout << "----------------" << endl;

	cout << "List: " << endl;
	random(size);
	for (int i = 0; i < length(); i++) {
		cout << operator[](i) << " ";
	}
	cout << endl;
	cout << "quickSort(): " << endl;
	quickSort(0, size - 1, typeSort);
	for (int i = 0; i < length(); i++) {
		cout << operator[](i) << " ";
	}
	cout << endl;
	cout << "----------------" << endl;
	for (int i = size - 1; i >= 0; i--) {
		del(i);
	}
	cout << "*Delete*" << endl;
	cout << "----------------" << endl;

	cout << "List: " << endl;
	random(size);
	for (int i = 0; i < length(); i++) {
		cout << operator[](i) << " ";
	}
	cout << endl;
	cout << "mergeSort(): " << endl;
	mergeSort(0, size - 1, typeSort);
	for (int i = 0; i < length(); i++) {
		cout << operator[](i) << " ";
	}
	cout << endl;
	cout << "----------------" << endl;
	for (int i = size - 1; i >= 0; i--) {
		del(i);
	}
	cout << "*Delete*" << endl;
	cout << "----------------" << endl;
}

template<typename L>
void List<L>::insertionSort(int size, bool typeSort) {
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = operator[](i);
		j = i - 1;
		if (typeSort == 0) {
			while (j >= 0 && operator[](j) < key)
			{
				operator[](j + 1) = operator[](j);
				j = j - 1;
			}
		}
		else {
			while (j >= 0 && operator[](j) > key)
			{
				operator[](j + 1) = operator[](j);
				j = j - 1;
			}
		}
		operator[](j + 1) = key;
	}
}

template<typename L>
int List<L>::partitionScheme0(int low, int high)
{
	int pivot = operator[](low);
	int i = (high + 1);

	for (int j = high; j >= low + 1; j--)
	{
		if (operator[](j) <= pivot)
		{
			i--;
			swap(operator[](i), operator[](j));
		}
	}
	swap(operator[](i - 1), operator[](low));
	return (i - 1);
}

template<typename L>
int List<L>::partitionScheme1(int low, int high)
{
	int pivot = operator[](high);
	int i = (low - 1);

	for (int j = low; j < high; j++)
	{
		if (operator[](j) <= pivot)
		{
			i++;
			swap(operator[](i), operator[](j));
		}
	}
	swap(operator[](i + 1), operator[](high));
	return (i + 1);
}

template<typename L>
void List<L>::quickSort(int low, int high, bool typeSort)
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

template<typename L>
void List<L>::mergeSort(int low, int high, bool typeSort)
{
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort(low, mid, typeSort);
		mergeSort(mid + 1, high, typeSort);
		merge(low, high, mid, typeSort);
	}
}

template<typename L>
void List<L>::merge(int low, int high, int mid, bool typeSort)
{
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
	if (typeSort == 0) {
		while (i <= mid && j <= high) {
			if (operator[](i) > operator[](j)) {
				c[k] = operator[](i);
				k++;
				i++;
			}
			else {
				c[k] = operator[](j);
				k++;
				j++;
			}
		}
	}
	else {
		while (i <= mid && j <= high) {
			if (operator[](i) < operator[](j)) {
				c[k] = operator[](i);
				k++;
				i++;
			}
			else {
				c[k] = operator[](j);
				k++;
				j++;
			}
		}
	}
	while (i <= mid) {
		c[k] = operator[](i);
		k++;
		i++;
	}
	while (j <= high) {
		c[k] = operator[](j);
		k++;
		j++;
	}
	for (i = low; i < k; i++) {
		operator[](i) = c[i];
	}
}