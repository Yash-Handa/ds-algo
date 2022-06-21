#include <iostream>
#include <vector>

void pre_to_post(std::vector<int> &v, int &i, int l, int u)
{
    if (i == v.size())
        return;

    if (v[i] < l || v[i] > u)
        return;

    int ele = v[i];
    i++;

    pre_to_post(v, i, l, ele);
    pre_to_post(v, i, ele, u);

    std::cout << ele << ' ';
}

int main()
{
    // std::vector<int> v = {40, 30, 35, 80, 100};
    std::vector<int> v = {40, 30, 32, 35, 80, 90, 100, 120};

    std::cout << "The given Pre-Order traversal is: ";
    for (const int &ele : v)
        std::cout << ele << ' ';
    std::cout << '\n';

    std::cout << "The given Post-Order traversal is: ";
    int i = 0;
    pre_to_post(v, i, INT32_MIN, INT32_MAX);
    std::cout << '\n';
}