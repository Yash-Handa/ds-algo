#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector, std::pair;

bool my_comp(const pair<int, int> &e1, const pair<int, int> &e2)
{
    return (e1.second > e2.second);
}

int job_sequencing(vector<pair<int, int>> &v)
{
    std::sort(v.begin(), v.end(), my_comp);
    std::unordered_map<int, int> mp; // map of taken slots and corresponding profits

    const int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        int j = v[i].first;
        while (mp.find(j) != mp.end())
            j--;

        if (j > 0)
            mp[j] = v[i].second;
    }

    int ans = 0;
    for (auto &ele : mp)
        ans += ele.second;

    return ans;
}

int main()
{
    // first --> deadline
    // second --> profit
    vector<pair<int, int>> v = {{4, 50}, {1, 5}, {1, 20}, {5, 10}, {5, 80}};

    std::cout << "The max profit is: " << job_sequencing(v) << '\n';
}