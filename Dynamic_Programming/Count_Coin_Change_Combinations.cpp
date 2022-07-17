#include <iostream>
#include <vector>

using std::vector;

int comb(vector<int> &coins, int sum)
{
    int c = coins.size();
    vector<vector<int>> table(sum + 1, vector<int>(c + 1, -1));

    for (int i = 0; i < c + 1; i++)
        table[0][i] = 1;

    for (int i = 1; i < sum + 1; i++)
        table[i][0] = 0;

    for (int i = 1; i < sum + 1; i++)
        for (int j = 1; j < c + 1; j++)
        {
            table[i][j] = table[i][j - 1];
            if (i >= coins[j - 1])
                table[i][j] += table[i - coins[j - 1]][j];
        }

    return table[sum][c];
}

int main()
{
    vector<int> coins = {2, 3, 5, 6};
    int sum = 10;

    std::cout << "The possible number of coin combinations are: " << comb(coins, sum) << '\n';
}