/*
? Given a binary sorted non-increasing array of 1s and 0s.
? You need to print the count of 1s in the binary array.
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
int count_ones(T b, T e)
{
    if (b == e)
        return 0;
    else if (*b == 0)
        return 0;

    T begin = b;
    T end = e;
    e--;
    while (b <= e)
    {
        T mid = b + floor(distance(b, e) / 2);

        if (*mid == 1)
        {
            if (mid + 1 == end || *(mid + 1) == 0)
                return distance(begin, mid) + 1;
            else
                b = mid + 1;
        }
        else
            e = mid - 1;
    }
    return 0;
}

int main()
{
    int arr[] = {1, 1, 1, 0, 0, 0, 0};
    // int arr[] = {1, 1, 1, 1, 1, 1, 1};
    // int arr[] = {1};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "Number of Ones is: " << count_ones(v.begin(), v.end()) << '\n';
    return 0;
}