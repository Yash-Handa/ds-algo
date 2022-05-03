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
void transpose(T &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
        for (int j = i + 1; j < cols; j++)
            swap(matrix[i][j], matrix[j][i]);
}

int main()
{
    int arr[][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}};
    vector<vector<int>> matrix;
    for (int i = 0; i < 4; i++)
    {
        vector<int> v;
        for (int j = 0; j < 4; j++)
            v.push_back(arr[i][j]);
        matrix.push_back(v);
    }

    cout << "Original Matrix: \n";
    display_matrix(matrix);

    transpose(matrix);

    cout << "\nResult Matrix: \n";
    display_matrix(matrix);
    return 0;
}