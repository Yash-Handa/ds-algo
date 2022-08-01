/*
? convert string s1 to s2 using operations [insert, remove, replace]
? Using Tabulation
*/
#include <iostream>
#include <vector>

using std::vector, std::string;

int edit_dist(string &s1, string &s2)
{
    const int m = s1.size(), n = s2.size();
    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));

    // set first col
    for (int i = 0; i < m + 1; i++)
        table[i][0] = i;

    // set first row
    for (int i = 0; i < n + 1; i++)
        table[0][i] = i;

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                table[i][j] = table[i - 1][j - 1];
            else
                table[i][j] = 1 + std::min(table[i - 1][j - 1], std::min(table[i][j - 1], table[i - 1][j]));
        }

    return table[m][n];
}

int main()
{
    string s1 = "saturday", s2 = "sunday";
    std::cout << "The number of moves req to convert " << s1 << " to " << s2 << " are: " << edit_dist(s1, s2) << '\n';
}