#include <iostream>
#include <vector>
#include <queue>

void k_sorted(std::vector<int> &v, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    const int sz = v.size();

    for (int i = 0; i <= k; i++)
        pq.push(v[i]);

    int index = 0;
    for (int i = k + 1; i < sz; i++)
    {
        v[index] = pq.top();
        pq.pop();
        index++;
        pq.push(v[i]);
    }

    while (!pq.empty())
    {
        v[index] = pq.top();
        pq.pop();
        index++;
    }
}

int main()
{
    std::vector<int> v = {9, 8, 7, 18, 19, 17};
    int k = 2;
    std::cout << "The given arr is:  ";
    for (const int &ele : v)
        std::cout << ele << ' ';
    std::cout << '\n';

    k_sorted(v, k);

    std::cout << "The sorted arr is: ";
    for (const int &ele : v)
        std::cout << ele << ' ';
    std::cout << '\n';
}