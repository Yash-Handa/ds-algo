#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::vector<int> v = {2, 8, 30, 15, 25, 12};

    std::set<int> s;
    s.insert(v[0]);
    std::cout << "-1 ";
    int sz = v.size();
    for (int i = 1; i < sz; i++)
    {
        auto ele = s.lower_bound(v[i]);
        if (ele == s.end())
            std::cout << "-1 ";
        else
            std::cout << *ele << ' ';

        s.insert(v[i]);
    }
    std::cout << '\n';
}