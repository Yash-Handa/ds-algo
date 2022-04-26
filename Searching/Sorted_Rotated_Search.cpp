#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
int r_b_s(T b, T e, int num)
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
        else if (*mid < *e)
        {
            // 2nd half is sorted

            if (*mid < num && num <= *e)
                b = mid + 1;
            else
                e = mid - 1;
        }
        else
        {
            // 1st half is sorted

            if (*b <= num && num < *mid)
                e = mid - 1;
            else
                b = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 50, 60, 5, 8};
    int num = 5;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    cout << "Index of " << num << " is: " << r_b_s(b, e, num) << '\n';
    return 0;
}