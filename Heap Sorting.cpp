// Heap Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
class Heap_Sort
{
public:
	int *arr;
	int size;
	int cap;

	Heap_Sort(int s)
	{
		size = s;
		cap = 0;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = -1;
		}
	}
	void insert(int val);
	int left_child(int i)
	{

		if ((i * 2) > size)
		{
			return i;
		}
		else
		{
			return i * 2;
		}
	}
	int right_child(int i)
	{
		if ((i * 2) + 1 > size)
		{
			return 0;
		}
		else
		{
			return (i * 2) + 1;
		}
	}
	int parent(int i)
	{
		if ((i / 2) < size)
		{
			return 0;
		}
		else
		{
			return i / 2;
		}
	}
	void Heapify(int arr[], int i, int size);
	void Buildify();
	void HeapSort(int arr[], int size);
	void Display();

};
void Heap_Sort::insert(int val)
{
	if (cap < size &&cap >= 0)
	{
		arr[cap] = val;
		cap++;
	}
	else
	{
		cout << "Array is full\n";
	}
}
void Heap_Sort::Display()
{
	for (int i = 1; i < size; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl;
}
void Heap_Sort::Heapify(int arr[], int i, int size)
{
	// sorting the element in decsending order

	int min = i;
	int l = left_child(i);
	int r = right_child(i);

	// left child is smaller
	if (l < size && arr[l] < arr[min])
	{
		min = l;
	}
	// If right child is smaller 
	if (r < size && arr[r] < arr[min])
	{
		min = r;
	}
	// If largest is not root 
	if (min != i)
	{
		swap(arr[i], arr[min]);

		// Recursively heapify the affected sub-tree 
		Heapify(arr, i, min);
	}


}
void Heap_Sort::Buildify()
{
	for (int i = (size / 2); i >= 1; i--)
	{
		Heapify(arr, i, size);
	}
}
void Heap_Sort::HeapSort(int arr[], int size)
{
	Buildify();
	int j = 1;
	for (int i = size - 1; i >= 1; i--)
	{
		// Move current root to end 
		swap(arr[j], arr[i]);

		// call min heapify function
		Heapify(arr, j, i);
	}
}
int main()
{
	Heap_Sort s(7);
	s.insert(0);
	s.insert(10);
	s.insert(1);
	s.insert(7);
	s.insert(9);
	s.insert(8);
	s.insert(2);
	s.HeapSort(s.arr, 7);
	s.Display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
