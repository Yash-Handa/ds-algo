#include <iostream>
#include <vector>

int lis(std::vector<int> &v)
{
    const int sz = v.size();
    std::vector<int> table(sz, 0); // 1-D table used to store intermidiate results
    table[0] = 1;

    for (int i = 1; i < sz; i++)
    {
        table[i] = 1;
        for (int j = i - 1; j >= 0; j--)
            // elements smaller than ith ele and comes before ith ele can be part of the increasing sub-sequence ending on ith ele
            if (v[j] < v[i])
                table[i] = std::max(table[i], table[j] + 1);
    }

    // find the max in table
    int ans = 1;
    for (int ele : table)
        ans = std::max(ans, ele);

    return ans;
}

int main()
{
    std::vector<int> v = {3, 4, 2, 8, 10, 5, 1};
    std::cout << "The length of the longest increasing sub-sequence is: " << lis(v) << '\n';
}
