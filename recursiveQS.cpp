#include <iostream>
#include <algorithm>
using namespace std;

int partition(int a[], int start, int end)
{
    // Pick the leftmost element as a pivot from the array
    int pivot = a[start];

    // elements less than the pivot will be pushed to the left of `pIndex`
    // elements more than the pivot will be pushed to the right of `pIndex`
    // equal elements can go either way
    int pIndex = start + 1;

    // each time we find an element less than or equal to the pivot it is placed before the pivot, and the 'pIndex' is incremented
    for (int i = start + 1; i <= end; i++)
    {
        if (a[i] <= pivot)
        {
            // swap `pIndex` with pivot
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    swap(a[pIndex - 1], a[start]);
    // return index of the pivot element
    return pIndex - 1;
}


void quicksort(int a[], int start, int end)
{
    // base condition
    if (start >= end) {
        return;
    }

    // rearrange elements across pivot
    int pivot = partition(a, start, end);

    // recur on subarray containing elements that are less than the pivot
    quicksort(a, start, pivot - 1);

    // recur on subarray containing elements that are more than the pivot
    quicksort(a, pivot + 1, end);
}

int main()
{
    int a[] = {6, -3, 5, 1, 9, 8, 3, 2, -6 };
    int n = sizeof(a) / sizeof(a[0]);

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
