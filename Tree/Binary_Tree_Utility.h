#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>

template <typename T>
struct Node
{
    typedef T data_type;
    data_type data;
    Node *l_child, *r_child;
    Node(data_type data) : data(data), l_child(nullptr), r_child(nullptr){};
};

template <class T>
class Binary_Tree
{
public:
    T *HEAD;
    typedef typename T::data_type data_type;

    Binary_Tree() : HEAD(nullptr){};

protected:
    T *insert_level_order(std::vector<data_type> &v, int i)
    {
        if (i >= v.size())
            return nullptr;

        T *curr = new T(v[i]);
        curr->l_child = insert_level_order(v, 2 * i + 1);
        curr->r_child = insert_level_order(v, 2 * i + 2);
        return curr;
    }

    void post_order_traversal(T *head)
    {
        if (!head)
            return;

        post_order_traversal(head->l_child);
        post_order_traversal(head->r_child);
        std::cout << head->data << ' ';
    }

    void pre_order_traversal(T *head)
    {
        if (!head)
            return;

        std::cout << head->data << ' ';
        pre_order_traversal(head->l_child);
        pre_order_traversal(head->r_child);
    }

    void in_order_traversal(T *head)
    {
        if (!head)
            return;

        in_order_traversal(head->l_child);
        std::cout << head->data << ' ';
        in_order_traversal(head->r_child);
    }

public:
    bool Breath_Vise_From_Vector(std::vector<data_type> &v)
    {
        if (HEAD)
            return false;

        HEAD = insert_level_order(v, 0);
        return true;
    }

    void post_order_traversal()
    {
        post_order_traversal(HEAD);
    }

    void pre_order_traversal()
    {
        pre_order_traversal(HEAD);
    }

    void in_order_traversal()
    {
        in_order_traversal(HEAD);
    }

    void display(int space = 2, bool display_null = true)
    {
        if (!HEAD)
        {
            std::cout << '\n';
            return;
        }
        std::queue<T *> q;
        std::vector<std::vector<data_type>> matrix(0, std::vector<data_type>(0));
        matrix.push_back(std::vector<data_type>());

        T *curr = HEAD, *new_line = new T(0);
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

        if (rows == 1) // only head is present
        {
            std::cout << matrix[0].front() << '\n';
            return;
        }

        int total_width = space * cols - 1;
        std::string null_str = display_null ? "_" : " ";
        for (int i = 0; i < rows; i++)
        {
            int sz = matrix[i].size();
            int between_space = total_width / sz;
            int start_space = between_space / 2;
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