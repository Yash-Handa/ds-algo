/*
? Given a sorted array arr[] of size N without duplicates, and given a value x.
? Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x.
? Find the index of K(0-based indexing).
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
int floor_(T b, T e, int x)
{
    if (b == e)
        return -1;

    T begin = b, end = e;
    int res_index = -1;
    e--;
    while (b <= e)
    {
        T mid = b + floor(distance(b, e) / 2);
        if (*mid == x)
            return distance(begin, mid);
        else if (*mid > x)
            e = mid - 1;
        else
        {
            if (mid + 1 == end || *(mid + 1) > x)
                return distance(begin, mid);

            res_index = distance(begin, mid);
            b = mid + 1;
        }
    }
    return res_index;
}

int main()
{
    int arr[] = {1, 2, 8, 10, 11, 12, 19};
    int x = 5;
    // int arr[] = {1, 2, 8, 10, 11, 12, 19};
    // int x = 0;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "Floor of " << x << " is at index: " << floor_(v.begin(), v.end(), x) << '\n';
    return 0;
}