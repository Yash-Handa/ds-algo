#include <iostream>
#include <vector>
#include <queue>

struct Data_Point
{
    int data, arr_idx, idx;
    Data_Point(int data, int arr_idx, int idx)
        : data(data), arr_idx(arr_idx), idx(idx) {}
};

struct Comp
{
    bool operator()(const Data_Point &e1, const Data_Point &e2)
    {
        return (e1.data > e2.data);
    }
};

std::vector<int> sort_k_arr(std::vector<std::vector<int>> &matrix)
{
    const int total_arrays = matrix.size();
    std::vector<int> ans;
    std::priority_queue<Data_Point, std::vector<Data_Point>, Comp> pq;

    for (int i = 0; i < total_arrays; i++)
        pq.push(Data_Point(matrix[i][0], i, 0));

    while (!pq.empty())
    {
        Data_Point temp = pq.top();
        pq.pop();
        ans.push_back(temp.data);

        if (temp.idx < matrix[temp.arr_idx].size() - 1)
            pq.push(Data_Point(matrix[temp.arr_idx][temp.idx + 1], temp.arr_idx, temp.idx + 1));
    }

    return ans;
}

int main()
{
    std::vector<std::vector<int>> matrix = {{10, 20},
                                            {5, 15},
                                            {4, 9, 11}};

    std::vector<int> ans = sort_k_arr(matrix);
    std::cout << "The Merged and Sorted elements are: ";
    for (const int &ele : ans)
        std::cout << ele << ' ';
    std::cout << '\n';
}