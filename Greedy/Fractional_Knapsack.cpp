#include <iostream>
#include <vector>
#include <algorithm>

using std::vector, std::pair;

bool my_comp(const pair<int, int> &e1, const pair<int, int> &e2)
{
    return ((e1.second / e1.first) > (e2.second / e2.first));
}

int fkp(vector<pair<int, int>> &v, const int cap)
{
    std::sort(v.begin(), v.end(), my_comp);
    int ans = 0, curr_cap = cap, i = 0, sz = v.size();

    while (curr_cap > 0 && i < sz)
    {
        if (curr_cap >= v[i].first)
        {
            ans += v[i].second;
            curr_cap -= v[i].first;
        }
        else
        {
            ans += curr_cap * (v[i].second / v[i].first);
            curr_cap = 0;
        }
        i++;
    }

    return ans;
}

int main()
{
    vector<pair<int, int>> v = {{50, 600}, {20, 500}, {30, 400}};
    const int cap = 70;

    std::cout << "The max amount that can be selected is: " << fkp(v, cap) << '\n';
}