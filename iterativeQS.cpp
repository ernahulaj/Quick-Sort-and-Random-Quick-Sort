#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
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


void iterativeQuicksort(int a[], int n)
{
    // create a stack of pairs for storing subarray start and end index
    stack<pair<int, int>> s;

    // get the starting and ending index of the given array
    int start = 0;
    int end = n - 1;

    // push the start and end index of the array into the stack
    s.push(make_pair(start, end));

    while (!s.empty())
    {
        // remove top pair from the list and get subarray starting and ending indices
        start = s.top().first, end = s.top().second;
        s.pop();

        // rearrange elements across pivot
        int pivot = partition(a, start, end);

        // push subarray indices containing elements that are less than the current pivot to stack
        if (pivot - 1 > start) {
            s.push(make_pair(start, pivot - 1));
        }

        // push subarray indices containing elements that are more than the current pivot to stack
        if (pivot + 1 < end) {
            s.push(make_pair(pivot + 1, end));
        }
    }
}

int main()
{
    int a[] = { 6, -3, 5, 1, 9, 8, 3, 2, -6 };
    int n = sizeof(a) / sizeof(a[0]);

    iterativeQuicksort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}




