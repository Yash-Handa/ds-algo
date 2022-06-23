#include <iostream>
#include <vector>
#include <queue>

int max_items(std::vector<int> &v, int sum)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(v.begin(), v.end());
    int count = 0, temp_sum = pq.top();
    while (sum >= temp_sum)
    {
        count++;
        pq.pop();

        temp_sum += pq.top();
    }

    return count;
}

int main()
{
    std::vector<int> v = {1, 12, 5, 111, 200};
    int sum = 10;

    std::cout << "The number of items that can be purchased are: " << max_items(v, sum) << '\n';
}