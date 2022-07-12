#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

bool is_safe(vector<vector<int>> &sudoku, const int sz, int row, int col, int num)
{
    // check if row or col already has the num
    for (int i = 0; i < sz; i++)
        if (sudoku[row][i] == num || sudoku[i][col] == num)
            return false;

    // check if the sub grid has the number
    int sub_sz = std::sqrt(sz);
    int sub_r = row - row % sub_sz;
    int sub_c = col - col % sub_sz;
    for (int i = sub_r; i < sub_r + sub_sz; i++)
        for (int j = sub_c; j < sub_c + sub_sz; j++)
            if (sudoku[i][j] == num)
                return false;

    return true;
}

bool solve(vector<vector<int>> &sudoku, const int sz)
{
    // find an empty cell
    int i = 0, j = 0;
    for (i = 0; i < sz; i++)
    {
        for (j = 0; j < sz; j++)
            if (sudoku[i][j] == 0)
                break;

        if (j < sz)
            break;
    }

    if (i == sz && j == sz)
        return true;

    for (int n = 1; n <= sz; n++)
        if (is_safe(sudoku, sz, i, j, n))
        {
            sudoku[i][j] = n;
            if (solve(sudoku, sz))
                return true;

            sudoku[i][j] = 0;
        }

    return false;
}

void display(vector<vector<int>> &sudoku)
{
    for (auto &row : sudoku)
    {
        for (int ele : row)
        {
            if (ele == 0)
                std::cout << "_  ";
            else
                std::cout << ele << "  ";
        }
        std::cout << '\n';
    }
}

int main()
{
    vector<vector<int>> sudoku = {{1, 0, 3, 0},
                                  {0, 0, 2, 1},
                                  {0, 1, 0, 2},
                                  {2, 4, 0, 0}};

    std::cout << "The given sudoku is:\n";
    display(sudoku);
    std::cout << '\n';

    if (solve(sudoku, sudoku.size()))
    {
        std::cout << "One of the possible solution is:\n";
        display(sudoku);
    }
    else
        std::cout << "The given sudoku cannot be solved.\n";
}