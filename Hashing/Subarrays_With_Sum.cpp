/*
? Given an unsorted array of integers, find the number of subarrays having sum exactly equal to a given number k.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int arr[] = {10, 2, -2, -20, 10};
    int sum = -10;

    // int arr[] = {0, 0, 5, 5, 0, 0};
    // int sum = 0;

    unordered_map<int, int> m;
    int pre_sum = 0, count = 0;

    for (int ele : arr)
    {
        pre_sum += ele;

        if (pre_sum == sum)
            count++;

        if (m.find(pre_sum - sum) != m.end())
            count += m[pre_sum - sum];

        m[pre_sum]++;
    }

    cout << "Number of occurrance of sub-arrays with sum " << sum << " is: " << count << '\n';
    return 0;
}