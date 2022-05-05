#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
int subarray_sum(T b, T e, int sum)
{
    unordered_map<int, int> map;
    T begin = b;
    int pre_sum = 0, res = 0;

    while (b < e)
    {
        pre_sum += *b;

        if (map.find(pre_sum) == map.end())
            map[pre_sum] = distance(begin, b);

        if (pre_sum == sum)
            res = distance(begin, b) + 1;
        else if (map.find(pre_sum - sum) != map.end())
            res = max(res, (int)distance(begin, b) - map[pre_sum - sum]);

        b++;
    }
    return res;
}

int main()
{
    int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int sum = 4;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "The size of the longest sub-array with sum " << sum << " is: " << subarray_sum(v.begin(), v.end(), sum) << '\n';
    return 0;
}