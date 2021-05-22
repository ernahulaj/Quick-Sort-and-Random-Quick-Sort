#include <iostream>
using namespace std;

int partition(int a[], int start, int end)
{
	int pivot = a[start];

	int pIndex = start + 1;

	for (int i = start + 1; i <= end; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}

	swap(a[pIndex - 1], a[start]);

	return pIndex - 1;
}


int randomizedPartition(int a[], int start, int end)
{
	// choose a random index between `start` and `end`
	int pivotIndex = rand() % (end - start + 1) + start;

	// swap the first element with the element present at random index
	swap(a[pivotIndex], a[start]);

	// call partition procedure
	return partition(a, start, end);
}


void quicksort(int a[], int start, int end)
{	if (start >= end) {
		return;
	}

	int pivot = randomizedPartition(a, start, end);

	quicksort(a, start, pivot - 1);

	quicksort(a, pivot + 1, end);
}

int main()
{
	int a[] = { 9, -3, 5, 2, 6, 8, -6, 1, 3 };
	int n = sizeof(a) / sizeof(a[0]);

	quicksort(a, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}