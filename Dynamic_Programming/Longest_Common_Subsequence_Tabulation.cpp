#include <iostream>
#include <vector>

using std::vector, std::string;

int lcs(string &s_1, string &s_2)
{
    const int sz_1 = s_1.size(), sz_2 = s_2.size();
    vector<vector<int>> table(sz_1 + 1, vector<int>(sz_2 + 1, -1));

    for (int i = 0; i < sz_2 + 1; i++)
        table[0][i] = 0;

    for (int i = 0; i < sz_1 + 1; i++)
        table[i][0] = 0;

    for (int i = 1; i < sz_1 + 1; i++)
        for (int j = 1; j < sz_2 + 1; j++)
            if (s_1[i - 1] == s_2[j - 1])
                table[i][j] = 1 + table[i - 1][j - 1];
            else
                table[i][j] = std::max(table[i][j - 1], table[i - 1][j]);

    return table[sz_1][sz_2];
}

int main()
{
    string s_1 = "AXYZ", s_2 = "BAZ";
    // string s_1 = "AXYZ", s_2 = "A";

    std::cout << "The length of longest common sub-sequence of " << s_1 << " and " << s_2 << " is: " << lcs(s_1, s_2) << '\n';
}
