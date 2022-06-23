#include <iostream>
#include <vector>
#include <queue>

float calc_median(std::priority_queue<int> &max_pq,
                  std::priority_queue<int, std::vector<int>, std::greater<int>> &min_pq)
{
    if (max_pq.size() > min_pq.size())
        return max_pq.top();
    return (max_pq.top() + min_pq.top()) / 2.0;
}

void stream_median(std::vector<int> &v)
{
    std::priority_queue<int> max_pq;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;

    // max_pq will have ele <= median and min_pq have ele >= median
    // for odd number of ele max_pq will have 1 more ele than min_pq
    // i.e., ether max_pq.size() == min_pq.size() OR max_pq.size() == min_pq.size() + 1

    max_pq.push(v[0]);
    std::cout << calc_median(max_pq, min_pq) << ' ';

    const int sz = v.size();
    for (int i = 1; i < sz; i++)
    {
        if (max_pq.size() > min_pq.size())
        {
            if (min_pq.empty() || v[i] >= min_pq.top())
                min_pq.push(v[i]);
            else
            {
                max_pq.push(v[i]);
                min_pq.push(max_pq.top());
                max_pq.pop();
            }
        }
        else
        {
            if (v[i] < max_pq.top())
                max_pq.push(v[i]);
            else
            {
                min_pq.push(v[i]);
                max_pq.push(min_pq.top());
                min_pq.pop();
            }
        }
        std::cout << calc_median(max_pq, min_pq) << ' ';
    }
}

int main()
{
    std::vector<int> v = {12, 15, 10, 5, 8, 7, 16};

    std::cout << "The given input stream is: ";
    for (const int &ele : v)
        std::cout << ele << ' ';
    std::cout << '\n';

    std::cout << "The median till here is:   ";
    stream_median(v);
    std::cout << '\n';
}