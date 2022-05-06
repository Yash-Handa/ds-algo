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
        pre_sum += *b;

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
    int arr_1[] = {0, 1, 0, 0, 0, 0};
    int arr_2[] = {1, 0, 1, 0, 0, 1};
    int s = sizeof(arr_1) / sizeof(arr_1[0]);
    vector<int> v;
    for (int i = 0; i < s; i++)
        v.push_back(arr_1[i]-arr_2[i]);

    cout << "The size of the longest common span with same sum in the two arrays: " << subarray(v.begin(), v.end()) << '\n';
    return 0;
}
