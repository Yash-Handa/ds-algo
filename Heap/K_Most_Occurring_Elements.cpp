/*
? Given an array arr[] of N integers in which elements may be repeating several times. Also, a positive number
? K is given and the task is to find sum of total frequencies of K most occurring elements

? Note: The value of K is guaranteed to be less than or equal to the number of distinct elements in arr.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

class comp
{
public:
    bool operator()(std::pair<int, int> &e1, std::pair<int, int> &e2)
    {
        return (e1.second < e2.second);
    }
};

int freq_sum(std::vector<int> &v, const int k)
{
    std::unordered_map<int, int> mp;
    for (const int &ele : v)
        mp[ele]++;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp>
        pq(mp.begin(), mp.end());

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += pq.top().second;
        pq.pop();
    }

    return sum;
}

int main()
{
    std::vector<int> v = {3, 1, 4, 4, 5, 2, 6, 1};
    const int k = 2;

    std::cout << "The sum of frequencies of " << k << " most occurring elements is: " << freq_sum(v, k) << '\n';
}