#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

template <typename T>
struct Node
{
    typedef T data_type;
    data_type data;
    Node *l_child, *r_child;
    Node(data_type data) : data(data), l_child(nullptr), r_child(nullptr) {}
};

template <typename T>
class Binary_Search_Tree
{
public:
    T *ROOT;
    typedef typename T::data_type data_type;

    Binary_Search_Tree() : ROOT(nullptr) {}

protected:
    T *tree_from_sorted_vector(std::vector<data_type> &v, int start, int end)
    {
        if (end < start)
            return nullptr;

        int mid = (start + end) / 2;
        T *curr = new T(v[mid]);
        curr->l_child = tree_from_sorted_vector(v, start, mid - 1);
        curr->r_child = tree_from_sorted_vector(v, mid + 1, end);
        return curr;
    }

public:
    Binary_Search_Tree(std::vector<data_type> &v)
    {
        std::sort(v.begin(), v.end());

        // remove duplicates
        int i = 0, j = 1, sz = v.size();
        for (; j < sz; j++)
            if (v[i] != v[j])
            {
                v[i + 1] = v[j];
                i++;
            }

        v.resize(i + 1);

        ROOT = tree_from_sorted_vector(v, 0, v.size() - 1);
    }

    Binary_Search_Tree(const int nodes)
    {
        int mod = 90 / nodes;
        std::vector<data_type> v(nodes);

        if (mod < 2)
            for (int i = 0; i < nodes; i++)
                v[i] = 10 + i;
        else
        {
            srand(time(0));
            v[0] = 10 + rand() % mod + 1;
            for (int i = 1; i < nodes; i++)
            {
                v[i] = v[i - 1] + rand() % mod + 1;
            }
        }

        ROOT = tree_from_sorted_vector(v, 0, v.size() - 1);
    }

    void display(int space = 2, bool display_null = true)
    {
        if (!ROOT)
        {
            std::cout << '\n';
            return;
        }
        std::queue<T *> q;
        std::vector<std::vector<data_type>> matrix(0, std::vector<data_type>(0));
        matrix.push_back(std::vector<data_type>());

        T *curr = ROOT, *new_line = new T(0);
        int height = 0;
        q.push(curr);
        q.push(new_line);
        while (!q.empty())
        {
            T *temp = q.front();
            q.pop();

            if (!temp)
            {
                matrix[height].push_back(data_type(INT32_MAX));

                q.push(nullptr);
                q.push(nullptr);
            }
            else if (temp == new_line)
            {
                bool last_level = true;
                for (data_type ele : matrix[height])
                    if (ele != data_type(INT32_MAX))
                    {
                        last_level = false;
                        break;
                    }

                if (last_level)
                    break;

                q.push(new_line);
                height++;
                matrix.push_back(std::vector<data_type>());
            }
            else
            {
                matrix[height].push_back(temp->data);

                q.push(temp->l_child);
                q.push(temp->r_child);
            }
        }

        // display data from the matrix
        int rows = matrix.size() - 1;
        int cols = matrix[rows - 1].size();

        if (rows == 1) // only root is present
        {
            std::cout << matrix[0].front() << '\n';
            return;
        }

        int total_width = (space * (cols - 1)) + 2 * cols;
        std::string null_str = display_null ? "__" : " ";
        for (int i = 0; i < rows; i++)
        {
            int sz = matrix[i].size();
            int between_space = total_width / sz - 1;
            int start_space = between_space / 2 - 1;
            if (i == 0)
                start_space += 1;
            std::string level(start_space, ' '), b_s(between_space, ' ');

            for (int j = 0; j < sz - 1; j++)
            {
                level += matrix[i][j] == data_type(INT32_MAX) ? null_str : std::to_string(matrix[i][j]);
                level += b_s;
            }

            level += matrix[i][sz - 1] == data_type(INT32_MAX) ? null_str : std::to_string(matrix[i][sz - 1]);
            std::cout << level << '\n';
        }
    }
};