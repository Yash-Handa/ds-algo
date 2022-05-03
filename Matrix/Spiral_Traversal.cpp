#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void spiral_traversal(T &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
            cout << matrix[top][j] << " ";
        top++;

        for (int i = top; i <= bottom; i++)
            cout << matrix[i][right] << " ";
        right--;

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
                cout << matrix[bottom][j] << " ";
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << matrix[i][left] << " ";
            left++;
        }
    }
    cout << '\n';
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

    spiral_traversal(matrix);
    return 0;
}