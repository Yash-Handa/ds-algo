#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
int subarray(T b, T e)
{
    unordered_map<int, int> m;
    T begin = b;
    int pre_sum = 0, res = 0;

    while (b < e)
    {
        pre_sum += *b == 0 ? -1 : 1;

        if (pre_sum == 0)
            res = distance(begin, b) + 1;
        else if (m.find(pre_sum) != m.end())
            res = max(res, (int)distance(begin, b) - m[pre_sum]);

        if (m.find(pre_sum) == m.end())
            m[pre_sum] = distance(begin, b);

        b++;
    }
    return res;
}

int main()
{
    int arr[] = {1, 0, 1, 1, 1, 0, 0};
    // int arr[] = {1};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "The size of the longest sub-array with equal 0's and 1's is: " << subarray(v.begin(), v.end()) << '\n';
    return 0;
}
