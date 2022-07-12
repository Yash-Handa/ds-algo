/*
? Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.
? Note: Each subset should be sorted.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void print_set(vector<int> &ans)
{
    int sz = ans.size();
    if (sz == 0)
        std::cout << "{ }\n";
    else
    {
        std::cout << "{ ";
        for (int i = 0; i < sz - 1; i++)
            std::cout << ans[i] << ", ";
        std::cout << ans[sz - 1] << " }\n";
    }
}

void uni_sets(vector<int> &v, vector<int> &ans, const int sz, int i)
{
    // print the current set
    print_set(ans);

    if (i == sz)
        return;

    for (int j = i; j < sz; j++)
    {
        if (j != i && v[j] == v[j - 1])
            continue;

        ans.push_back(v[j]);
        uni_sets(v, ans, sz, j + 1);
        ans.erase(ans.end() - 1);
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 3};
    std::cout << "All unique sets are:\n";
    std::sort(v.begin(), v.end());
    vector<int> ans;
    uni_sets(v, ans, v.size(), 0);
}