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
void rotate(T &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();

    // transpose of the matrix
    for (int i = 0; i < rows; i++)
        for (int j = i + 1; j < cols; j++)
            swap(matrix[i][j], matrix[j][i]);

    // reverse each column
    for (int j = 0; j < cols; j++)
    {
        int b = 0, e = rows - 1;
        while (b <= e)
        {
            swap(matrix[b][j], matrix[e][j]);
            b++;
            e--;
        }
    }
}

int main()
{
    int arr[][4] = {{11, 12, 13, 14},
                    {15, 16, 17, 18},
                    {19, 20, 21, 22},
                    {23, 24, 25, 26}};
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

    rotate(matrix);

    cout << "\nResult Matrix: \n";
    display_matrix(matrix, " | ", " |\n");
    return 0;
}