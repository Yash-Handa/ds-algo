#include <iostream>
#include <vector>

using std::vector, std::string;

int lcs(vector<vector<int>> &memo, string &s_1, string &s_2, int ind_1, int ind_2)
{
    if (ind_1 == -1 || ind_2 == -1)
        return 0;

    if (memo[ind_1][ind_2] == -1)
    {
        if (s_1[ind_1] == s_2[ind_2])
            memo[ind_1][ind_2] = 1 + lcs(memo, s_1, s_2, ind_1 - 1, ind_2 - 1);
        else
            memo[ind_1][ind_2] = std::max(lcs(memo, s_1, s_2, ind_1 - 1, ind_2),
                                          lcs(memo, s_1, s_2, ind_1, ind_2 - 1));
    }

    return memo[ind_1][ind_2];
}

int main()
{
    string s_1 = "AXYZ", s_2 = "BAZ";
    // string s_1 = "AXYZ", s_2 = "A";

    vector<vector<int>> memo(s_1.size(), vector<int>(s_2.size(), -1));
    std::cout << "The length of longest common sub-sequence of " << s_1 << " and " << s_2 << " is: " << lcs(memo, s_1, s_2, s_1.size() - 1, s_2.size() - 1) << '\n';
}