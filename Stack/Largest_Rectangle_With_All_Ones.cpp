#include <iostream>
#include <vector>
#include <stack>

using std::vector;

template <typename T>
int largest_area_histogram(vector<T> &hist)
{
    std::stack<T> s;
    int hist_size = hist.size(), res = 0;
    for (int i = 0; i < hist_size; i++)
    {
        while (!s.empty() && hist[s.top()] > hist[i])
        {
            int length = hist[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            res = std::max(res, length * width);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int length = hist[s.top()];
        s.pop();
        int width = s.empty() ? hist_size : hist_size - s.top() - 1;
        res = std::max(res, length * width);
    }

    return res;
}

template <typename T>
int largest_area_matrix(vector<vector<T>> &matrix)
{
    int ROWS = matrix.size(), COLS = matrix[0].size();
    int res = largest_area_histogram(matrix[0]);
    for (int i = 1; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            if (matrix[i][j] == 1)
                matrix[i][j] += matrix[i - 1][j];

        res = std::max(res, largest_area_histogram(matrix[i]));
    }

    return res;
}

int main()
{
    int mat[4][5] = {{1, 0, 0, 1, 1},
                     {0, 0, 0, 1, 1},
                     {1, 1, 1, 1, 1},
                     {0, 1, 1, 1, 1}};

    vector<vector<int>> matrix(0, vector<int>());
    for (int i = 0; i < 4; i++)
    {
        vector<int> row;
        for (int j = 0; j < 5; j++)
            row.push_back(mat[i][j]);
        matrix.push_back(row);
    }

    std::cout << "The size of the largest possible rectangle of all 1's in the given matrix is: " << largest_area_matrix(matrix) << '\n';
    return 0;
}