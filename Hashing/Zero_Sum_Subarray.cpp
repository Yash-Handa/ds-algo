#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <typename T>
bool is_0_subarray(T b, T e)
{
    unordered_set<int> s;
    int pre_sum = 0;
    s.insert(0);

    while (b < e)
    {
        pre_sum += *b;

        if (s.find(pre_sum) != s.end())
            return true;

        s.insert(pre_sum);
        b++;
    }
    return false;
}

int main()
{
    int arr[] = {3, 4, 3, -1, 1};
    // int arr[] = {-3, 2, 1, 4};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    if (is_0_subarray(v.begin(), v.end()) == true)
        cout << "The array has a sub array with size 0\n";
    else
        cout << "There exist no sub array with size 0\n";

    return 0;
}