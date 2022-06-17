/*
? Given an array containing N integers and a positive integer K,
? find the length of the longest sub array with sum of the elements divisible by the given value K.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

int max_subarray(std::vector<int> &v, int k)
{
    std::unordered_map<int, int> mp;
    int sum = 0, ans = 0, sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        sum += v[i]; // for prefix sum
        int rem = sum % k;
        if (rem == 0)
        {
            ans = std::max(ans, i + 1);
            continue;
        }
        else if (rem < 0)
            rem += k;

        auto ele = mp.find(rem);
        if (ele == mp.end())
            mp[rem] = i;
        else
            ans = std::max(ans, i - ele->second);
    }
    return ans;
}

int main()
{
    std::vector<int> v = {-2, 2, -5, 12, -11, -1, 7};
    int k = 3;

    std::cout << "The max length of the sub array divisible by " << k << " is: " << max_subarray(v, k) << '\n';
}