#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
bool is_possible(T b, T e, int max, int k)
{
    int req = 1, sum = 0;
    while (b < e)
    {
        if (sum + *b > max)
        {
            req++;
            sum = *b;
        }
        else
            sum += *b;
        b++;
    }

    return (req <= k);
}

template <typename T>
int min_pages(T b, T e, int k)
{
    T begin = b, end = e;
    int mx = 0, sum = 0;
    while (b < e)
    {
        sum += *b;
        mx = max(mx, *b);
        b++;
    }

    b = begin;

    int low = mx, high = sum, res = 0;
    while (low <= high)
    {
        int mid = floor((low + high) / 2);

        if (is_possible(b, e, mid, k) == true)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return res;
}

int main()
{
    int arr[] = {10, 5, 30, 20, 15};
    int k = 3;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    cout << "The minimum number of pages read by the most book reader is: " << min_pages(b, e, k) << '\n';
    return 0;
}