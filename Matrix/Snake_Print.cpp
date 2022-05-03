#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void snake_print(T b, T e)
{
    int row = 0;
    while (b < e)
    {
        vector<int>::iterator r_b = (*b).begin(), r_e = (*b).end();
        if (row % 2 == 0)
        {
            // print forward
            while (r_b < r_e)
            {
                cout << *r_b << " ";
                r_b++;
            }
        }
        else
        {
            // print backwords
            r_e--;
            while (r_b <= r_e)
            {
                cout << *r_e << " ";
                r_e--;
            }
        }
        b++;
        row++;
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

    snake_print(matrix.begin(), matrix.end());
    return 0;
}