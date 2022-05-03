#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void search_matrix(T &matrix, int num)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int i = 0, j = cols - 1;
    while (i < rows && j >= 0)
    {
        if (matrix[i][j] == num)
        {
            cout << num << " is present at location: (" << i << ", " << j << ")"<<'\n';
            return;
        }
        else if (matrix[i][j] > num)
            j--;
        else
            i++;
    }
    cout << num << " is not pressnet\n";
}

int main()
{
    int arr[][4] = {{11, 12, 13, 14},
                    {15, 16, 17, 18},
                    {19, 20, 21, 22},
                    {23, 24, 25, 26}};
    int num = 20;
    vector<vector<int>> matrix;
    for (int i = 0; i < 4; i++)
    {
        vector<int> v;
        for (int j = 0; j < 4; j++)
            v.push_back(arr[i][j]);
        matrix.push_back(v);
    }
    search_matrix(matrix, num);
    return 0;
}