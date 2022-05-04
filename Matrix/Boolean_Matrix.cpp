/*
? Given a boolean matrix of size RxC where each cell contains either 0 or 1,
? modify it such that if a matrix cell matrix[i][j] is 1 then
? all the cells in its ith row and jth column will become 1.
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
void bool_convert(T &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    bool first_row = false, first_col = false;

    for (int j = 0; j < cols; j++)
        if (matrix[0][j] == 1)
        {
            first_row = true;
            break;
        }

    for (int i = 0; i < rows; i++)
        if (matrix[i][0] == 1)
        {
            first_col = true;
            break;
        }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 1)
            {
                matrix[i][0] = 1;
                matrix[0][j] = 1;
            }
        }
    }

    for (int i = 1; i < rows; i++)
        for (int j = 1; j < cols; j++)
            if (matrix[i][0] == 1 || matrix[0][j] == 1)
                matrix[i][j] = 1;

    if (first_row == true)
        for (int j = 0; j < cols; j++)
            matrix[0][j] = 1;

    if (first_col == true)
        for (int i = 0; i < rows; i++)
            matrix[i][0] = 1;
}

int main()
{
    int arr[][4] = {{1, 0, 0, 0},
                    {1, 0, 0, 0},
                    {1, 0, 0, 0},
                    {0, 0, 0, 0}};
    vector<vector<int>> matrix;
    for (int i = 0; i < 4; i++)
    {
        vector<int> v;
        for (int j = 0; j < 4; j++)
            v.push_back(arr[i][j]);
        matrix.push_back(v);
    }

    cout << "Original Matrix: \n";
    display_matrix(matrix, " | ", " |\n");

    bool_convert(matrix);

    cout << "\nResult Matrix: \n";
    display_matrix(matrix, " | ", " |\n");
    return 0;
}