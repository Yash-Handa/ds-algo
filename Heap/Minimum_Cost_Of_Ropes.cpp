/*
? There are given N ropes of different lengths, we need to connect these ropes into one rope.
? The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.
*/
#include <iostream>
#include <vector>
#include <queue>

int min_cost(std::vector<int> &v)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(v.begin(), v.end());
    int cost = 0;
    while (!pq.empty())
    {
        int ele1 = pq.top();
        pq.pop();

        if (pq.empty())
            break;
        int ele2 = pq.top();
        pq.pop();

        pq.push(ele1 + ele2);
        cost += ele1 + ele2;
    }
    return cost;
}

int main()
{
    std::vector<int> v = {4, 3, 2, 6};
    // std::vector<int> v = {4, 2, 7, 6, 9};
    std::cout << "The minimum cost of joining the ropes is: " << min_cost(v) << '\n';
}