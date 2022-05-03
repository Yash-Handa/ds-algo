#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_boundaries(T &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();

    if (rows == 1)
        for (int i = 0; i < cols; i++)
            cout << matrix[0][i] << " ";
    else if (cols == 1)
        for (int i = 0; i < rows; i++)
            cout << matrix[i][0] << " ";
    else
    {
        for (int i = 0; i < cols; i++)
            cout << matrix[0][i] << " ";

        for (int i = 1; i < rows; i++)
            cout << matrix[i][cols - 1] << " ";

        for (int i = cols - 2; i >= 0; i--)
            cout << matrix[rows - 1][i] << " ";

        for (int i = rows - 2; i > 0; i--)
            cout << matrix[i][0] << " ";
    }
    cout << '\n';
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

    print_boundaries(matrix);
    return 0;
}