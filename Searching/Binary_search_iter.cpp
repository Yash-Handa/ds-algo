#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
int b_s(T b, T e, int num)
{
    T begin = b;
    if (b == e)
        return -1;

    e--;
    while (b <= e)
    {
        T mid = b + floor(distance(b, e) / 2);
        if (*mid == num)
            return distance(begin, mid);
        else if (*mid > num)
            e = mid - 1;
        else
            b = mid + 1;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int num = 7;
    // int arr[] = {10, 15};
    // int num = 20;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    cout << "Index of " << num << " is: " << b_s(b, e, num) << '\n';
    return 0;
}