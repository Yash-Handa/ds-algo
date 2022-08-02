/*
? Longest Increasing Sub-sequence using binary search.
*/
#include <iostream>
#include <vector>

int ceil_idx(std::vector<int> &v, const int ele)
{
    int s = 0, e = v.size() - 1;
    int ceil = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (v[mid] == ele)
            return mid;
        else if (v[mid] > ele)
        {
            ceil = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return ceil;
}

int lis(std::vector<int> &v)
{
    std::vector<int> lis_lens;
    lis_lens.push_back(v[0]);
    const int sz = v.size();
    for (int i = 1; i < sz; i++)
    {
        if (v[i] > lis_lens[lis_lens.size() - 1])
            lis_lens.push_back(v[i]);
        else
        {
            int c = ceil_idx(lis_lens, v[i]);
            lis_lens[c] = v[i];
        }
    }

    return lis_lens.size();
}

int main()
{
    std::vector<int> v = {3, 4, 2, 8, 10, 5, 1};
    std::cout << "The length of the longest increasing sub-sequence (using binary search) is: " << lis(v) << '\n';
}