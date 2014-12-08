#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef struct heapArr
{
	int data;
	int row;
	int col;
} heapArr;

typedef struct PriorityQueue
{
	heapArr *a;
	int size;
	int count;
} MinHeap;

void swap (heapArr *a , heapArr *b)
{
	heapArr t = *a;
	*a = *b;
	*b = t;
}

void printArr(heapArr a[], int n)
{
	for (int i = 0 ; i < n; i++)
		cout << a[i].data << " ";
	cout << endl;
}

MinHeap * createHeap(int a, int s)
{
	MinHeap *m = (MinHeap*) malloc(sizeof(MinHeap));
	m->size = s;
	m->a = (heapArr *) malloc(sizeof(heapArr) * s);
	/*  for (int i = 0; i < s ; i++)
	        m->a[i].data = 10000;
	*/
	m->a[0].data = a;
	m->a[0].row = 0;
	m->a[0].col = 0;
	m->count = 1;
	return m;
}

int getParent(int i)
{
	int t = (i - 1) / 2;
	if (t < 0)
		return -1;
	return t;
}

void insertHeap(MinHeap *m , int d, int r, int c)
{
	int i;
	i = m->count;
	if (++m->count > m->size)
	{
		cout << "ERROR!!";
		return;
	}
	m->a[i].data = d;
	m->a[i].row = r;
	m->a[i].col = c;
	while (i >= 0)
	{
		int p = getParent(i);
		if (m->a[i].data > m->a[p].data)
		{
			swap(m->a[i], m->a[p]);
			i = p;
		}
		else
		{
			break;
		}
	}
}

int getLeft(int i, int c)
{
	int t = 2 * i + 1;
	if (t > c)
		return -1;
	else
		return t;
}

int getRight(int i, int c)
{
	int t = 2 * i + 2;
	if (t > c)
		return -1;
	else
		return t;
}

void Heapify(MinHeap *m, int i)
{
	int min;
	int l = getLeft(i, m->count);
	int r = getRight(i, m->count);
	if (l != -1 && m->a[i].data < m->a[l].data)
		min = l;
	else
		min = i;
	if (r != -1 && m->a[min].data < m->a[r].data)
		min = r;

	if (min != i)
	{
		swap(m->a[min], m->a[i]);
		Heapify(m, min);
	}
}

heapArr DeleteMin(MinHeap *m)
{
	heapArr t = m->a[0];
	m->a[0] = m->a[m->count - 1];
	--m->count;
	Heapify(m, 0);
	return t;
}

int KthSmallest(int a[][3], int n, int m, int k)
{
	MinHeap *heap = createHeap(a[0][0], 2 * k);
	heapArr d = DeleteMin(heap);
	printArr(heap->a, heap->count);
	while (k > 1)
	{
		k--;
		if (d.row + 1 < n && a[d.row + 1][d.col] > d.data)
			insertHeap(heap, a[d.row + 1][d.col], d.row + 1, d.col);
		printArr(heap->a, heap->count);

		if (d.col + 1 < m && a[d.row][d.col + 1] > d.data)
			insertHeap(heap, a[d.row][d.col + 1], d.row, d.col + 1);
		printArr(heap->a, heap->count);
		d = DeleteMin(heap);
		printArr(heap->a, heap->count);

	}
	return d.data;
}

int main()
{
	int a[3][3] =
	{
		1, 3, 5,
		2, 4, 8,
		7, 9, 12
	};

	cout << "\n\n\n Kth Smallest: " << KthSmallest(a, 3, 3, 9) << endl;
}
