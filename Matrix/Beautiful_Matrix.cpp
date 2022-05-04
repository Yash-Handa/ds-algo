/*
? A beautiful matrix is a matrix in which the sum of elements in each row and column is equal.
? Given a square matrix of size NxN. Find the minimum number of operation(s) that are required to make the matrix beautiful.
? In one operation you can increment the value of any one cell by 1.
*/
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void display_matrix(T &matrix, string col_sep = " , ", string row_sep = "\n")
{
    int rows = matrix.size();
    if (rows == 0)
    {
        cout << "An empty matrix... \n";
        return;
    }

    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        int j = 0;
        for (j = 0; j < cols - 1; j++)
            cout << matrix[i][j] << col_sep;
        cout << matrix[i][j] << row_sep;
    }
}

template <typename T>
int beautify(T &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> row_sum(rows, 0);
    vector<int> col_sum(cols, 0);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            row_sum[i] += matrix[i][j];
            col_sum[j] += matrix[i][j];
        }

    int max_sum = 0;
    for (int i = 0; i < rows; i++)
        max_sum = max(max_sum, row_sum[i]);

    for (int j = 0; j < cols; j++)
        max_sum = max(max_sum, col_sum[j]);

    int i = 0, j = 0, count = 0;
    while (i < rows && j < cols)
    {
        int diff = min(max_sum - row_sum[i], max_sum - col_sum[j]);

        matrix[i][j] += diff;
        row_sum[i] += diff;
        col_sum[j] += diff;
        count += diff;

        if (row_sum[i] == max_sum)
            i++;

        if (col_sum[j] == max_sum)
            j++;
    }

    return count;
}

int main()
{
    int arr[3][3] = {{1, 2, 3},
                     {4, 2, 3},
                     {3, 2, 1}};
    vector<vector<int>> matrix;
    for (int i = 0; i < 3; i++)
    {
        vector<int> v;
        for (int j = 0; j < 3; j++)
            v.push_back(arr[i][j]);
        matrix.push_back(v);
    }

    cout << "Original Matrix: \n";
    display_matrix(matrix, " | ", " |\n");

    int moves = beautify(matrix);

    cout << "\nResult Matrix: \n";
    display_matrix(matrix, " | ", " |\n");

    cout << "The number of moves required were: " << moves << '\n';
    return 0;
}