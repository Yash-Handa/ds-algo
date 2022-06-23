#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::vector<int> v = {42, 56, 32, 78, 12, 90, 44};
    int k = 3;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(v.begin(), v.begin() + k);
    const int sz = v.size();
    for (int i = k; i < sz; i++)
    {
        if (v[i] > pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }

    std::cout << "The " << k << " largest items are: ";
    while (!pq.empty())
    {
        std::cout << pq.top() << ' ';
        pq.pop();
    }
    std::cout << '\n';
}