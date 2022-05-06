#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <typename T>
int subarray(T b, T e)
{
    unordered_set<int> s(b, e);
    int res = 0;

    while (b < e)
    {
        if (s.find(*b - 1) == s.end())
        {
            int count = 1;
            while (s.find(*b + count) != s.end())
            {
                count++;
            }
            res = max(res, count);
        }
        b++;
    }

    return res;
}

int main()
{
    int arr[] = {3, 8, 4, 5, 7};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "The size of the longest consecutive subsequence is: " << subarray(v.begin(), v.end()) << '\n';
    return 0;
}