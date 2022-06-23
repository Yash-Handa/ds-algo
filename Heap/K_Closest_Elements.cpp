#include <iostream>
#include <vector>
#include <queue>

void k_closest(std::vector<int> &v, int x, int k)
{
    std::priority_queue<std::pair<int, int>> pq;

    for (int i = 0; i < k; i++)
        pq.push({std::abs(x - v[i]), v[i]});

    const int sz = v.size();
    for (int i = k; i < sz; i++)
        if (std::abs(x - v[i]) < pq.top().first)
        {
            pq.pop();
            pq.push({std::abs(x - v[i]), v[i]});
        }

    while (!pq.empty())
    {
        std::cout << pq.top().second << ' ';
        pq.pop();
    }
}

int main()
{
    std::vector<int> v = {30, 40, 32, 33, 36, 37};
    int x = 38, k = 3;

    std::cout << "The " << k << " closest elements to " << x << " are: ";
    k_closest(v, x, k);
    std::cout << '\n';
}