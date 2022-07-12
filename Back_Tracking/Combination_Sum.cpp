/*
? Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B.
? The same number may be chosen from the array any number of times to make B.

? Note:
?   1. All numbers will be positive integers.
?   2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
?   3. The combinations themselves must be sorted in ascending order.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void make_comb(vector<int> &v, vector<int> &ans, int sum, int i)
{
    if (sum == 0)
    {
        // print the ans vector
        for (int ele : ans)
            std::cout << ele << ' ';
        std::cout << '\n';
        return;
    }

    int sz = v.size();
    for (int j = i; j < sz; j++)
    {
        if (sum - v[j] < 0)
            break;

        ans.push_back(v[j]);
        make_comb(v, ans, sum - v[j], j);
        ans.erase(ans.end() - 1);
    }
}

int main()
{
    // vector<int> v = {7, 2, 6, 5};
    // int sum = 16;

    vector<int> v = {8, 1, 8, 6, 8};
    int sum = 12;

    std::cout << "All the possible combinations with sum " << sum << " are:\n";
    std::sort(v.begin(), v.end());

    // remove duplicates
    int i = 0;
    for (int j = 1; j < v.size(); j++)
        if (v[i] != v[j])
        {
            i++;
            v[i] = v[j];
        }
    v.resize(i + 1);

    vector<int> ans;
    make_comb(v, ans, sum, 0);
}