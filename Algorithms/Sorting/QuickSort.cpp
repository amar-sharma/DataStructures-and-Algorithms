/* This program contains sample QuickSort program
 * in c++.
 * */
#include <iostream>

using namespace std;

void swap(int *a , int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int a[], int l, int r)
{
	int pivot = a[l];
	int left = l, right = r;
	while (left < right)
	{
		while (a[left] <= pivot)
			left++;
		while (a[right] > pivot)
			right--;
		if (left < right)
			swap(a[left], a[right]);
	}
	swap(a[l],a[right]);
	return right;
}

void QuickSort(int a[], int left, int right)
{
	int partition;
	if (left < right)
	{
		partition = Partition(a, left, right);
		QuickSort(a, left, partition - 1);
		QuickSort(a, partition + 1, right);
	}
}

int main()
{
	int array[] = {23, 56, -4, 23, -123, 2133, 44};
	int i;
	QuickSort(array, 0, 6);
	for (i = 0; i < 7; i++)
		cout << " " << array[i];
	cout << endl;
}
