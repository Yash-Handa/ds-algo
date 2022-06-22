#include <iostream>
#include <vector>

template <typename T>
void max_heapify(T b, T e, T i)
{
    while (i < e)
    {
        T max = i,
          l_child = b + std::distance(b, i) * 2 + 1,
          r_child = l_child + 1;

        if ((l_child < e) && (*l_child > *max))
            max = l_child;
        if ((r_child < e) && (*r_child > *max))
            max = r_child;

        if (max == i)
            break;

        std::swap(*i, *max);
        i = max;
    }
}

int main()
{
    std::vector<int> v = {2, 4, 3, 5, 6, 9};
    std::cout << "The given arr is:  ";
    for (const int &ele : v)
        std::cout << ele << ' ';
    std::cout << '\n';

    const int sz = v.size();
    for (int i = (sz - 2) / 2; i >= 0; i--)
        max_heapify(v.begin(), v.end(), v.begin() + i);

    for (int i = 0; i < sz - 1; i++)
    {
        std::swap(v[0], v[sz - 1 - i]);
        max_heapify(v.begin(), v.end() - i - 1, v.begin());
    }

    std::cout << "The sorted arr is: ";
    for (const int &ele : v)
        std::cout << ele << ' ';
    std::cout << '\n';
}