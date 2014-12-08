/* This program contains sample QuickSort program
 * in c++.
 */
#include <iostream>

using namespace std;

int count = 0;

void swaps(int *a , int *b)
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
            swaps(&a[left], &a[right]);
    }
    swaps(&a[l], &a[right]);
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
    int N;
    cin >> N;
    int *array = new int[N];
    for (int i = 0; i < N ; i++)
        cin >> array[i];
    QuickSort(array, 0, N - 1);
    for (int i = 0; i < N; i++)
        cout << " " << array[i];
    cout << endl << count;
}
