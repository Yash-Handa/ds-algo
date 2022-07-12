//? Given a N x N chess board find if N queens can be placed on it without attacking each other
#include <iostream>
#include <vector>

using std::vector;

bool is_safe(vector<vector<bool>> &board, const int n, int row, int col)
{
    // check if any previous queen (column) has occupied the row
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // now check for the diagonals
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool queens(vector<vector<bool>> &board, const int n, int col)
{
    if (col == n)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (is_safe(board, n, i, col))
        {
            board[i][col] = true;
            if (queens(board, n, col + 1))
                return true;

            board[i][col] = false;
        }
    }

    return false;
}

int main()
{
    const int n = 5;

    vector<vector<bool>> board(n, vector<bool>(n, false));
    if (queens(board, n, 0))
    {
        std::cout << n << " queens can be placed on a " << n << " x " << n << " chess board.\n";
        for (auto &row : board)
        {
            for (bool ele : row)
                std::cout << (ele ? 'Q' : '_') << ' ';
            std::cout << '\n';
        }
    }
    else
        std::cout << n << " queens cannot be placed on a " << n << " x " << n << " chess board.\n";
}