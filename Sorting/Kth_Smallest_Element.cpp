#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T lomuto(T b, T e)
{
    T i = b - 1, j = b;
    int pivot = *e;
    while (j < e)
    {
        if (*j < pivot)
        {
            i++;
            swap(*i, *j);
        }
        j++;
    }
    i++;
    swap(*i, *e);
    return i;
}

template <typename T>
int kth_smallest(T b, T e, int k)
{
    T begin = b;
    e--;
    while (b <= e)
    {
        T partition = lomuto(b, e);
        if (distance(begin, partition) == k - 1)
            return *partition;
        else if (distance(begin, partition) < k - 1)
            b = partition + 1;
        else
            e = partition - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 5, 3, 12, 6, 7};
    int k = 3;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "The " << k << " smallest element is: " << kth_smallest(v.begin(), v.end(), k) << '\n';
    return 0;
}