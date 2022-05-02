#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
void display_container(T start, T end, string seperator = ",")
{
    if (start == end)
    {
        cout << "AN Empty container....\n";
        return;
    }
    end--;
    while (start != end)
    {
        cout << *start << " " << seperator << " ";
        start++;
    }
    cout << *start << '\n';
}

template <typename T>
void heapify(T b, T e, T i)
{
    T largest = i, left = b + distance(b, i) * 2 + 1, right = b + distance(b, i) * 2 + 2;
    if ((left < e) && (*left > *largest))
        largest = left;
    if ((right < e) && (*right > *largest))
        largest = right;

    if (largest != i)
    {
        swap(*i, *largest);
        heapify(b, e, largest);
    }
}

template <typename T>
void heap_sort(T b, T e)
{
    // build the first max_heap.
    T i = b + floor((distance(b, e) - 1) / 2);
    while (i >= b)
    {
        heapify(b, e, i);
        i--;
    }

    // swap first (largest) element with last element.
    e--;
    swap(*b, *e);

    // call heapify for all the elements in the array.
    e--; // second last element
    while (b < e)
    {
        heapify(b, e + 1, b);
        swap(*b, *e);
        e--;
    }
}

int main()
{
    int arr[] = {4, 10, 3, 5, 1, 20};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    cout << "Before Sorting: ";
    display_container(b, e);

    heap_sort(b, e);

    cout << "After Sorting:  ";
    display_container(b, e);

    return 0;
}