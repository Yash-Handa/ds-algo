#include <iostream>
#include <vector>
#include <algorithm>

using std::vector, std::pair;

bool my_comp(const pair<int, int> &e1, const pair<int, int> &e2)
{
    return (e1.second < e2.second);
}

vector<pair<int, int>> act_select(vector<pair<int, int>> &v)
{
    std::sort(v.begin(), v.end(), my_comp);
    vector<pair<int, int>> ans;

    const int sz = v.size();
    ans.push_back(v[0]);
    int overlap = v[0].second;

    for (int i = 1; i < sz; i++)
        if (v[i].first >= overlap)
        {
            ans.push_back(v[i]);
            overlap = v[i].second;
        }

    return ans;
}

int main()
{
    vector<pair<int, int>> v = {{12, 25}, {10, 20}, {20, 30}};

    vector<pair<int, int>> ans = act_select(v);
    std::cout << "The maximum selected activities are: " << ans.size() << '\n';
    for (auto &ele : ans)
        std::cout << ele.first << " -> " << ele.second << '\n';
}