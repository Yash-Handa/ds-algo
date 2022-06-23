#include <iostream>
#include <vector>
#include <queue>

int k_smallest(std::vector<int> &v, const int k)
{
    const int sz = v.size();
    if (k >= sz)
        return INT32_MIN;

    std::priority_queue<int> pq(v.begin(), v.begin() + k);
    for (int i = k; i < sz; i++)
    {
        if (v[i] < pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }
    return pq.top();
}

int main()
{
    std::vector<int> v = {3, 5, 4, 2, 9};
    const int k = 3;

    std::cout << "The " << k << " smallest element is: " << k_smallest(v, k) << '\n';
}