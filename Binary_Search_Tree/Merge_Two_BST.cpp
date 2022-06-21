/*
? Given two BSTs, return elements of both BSTs in sorted form.
*/
#include <iostream>
#include <stack>
#include "Binary_Search_Tree_Utility.h"

void merge(Node<int> *root_1, Node<int> *root_2)
{
    if (!root_1 && !root_2)
        return;

    std::stack<Node<int> *> s_1, s_2;
    Node<int> *curr_1 = root_1, *curr_2 = root_2;

    std::cout << "The in-order traversal of the merged BST is: ";
    while ((!s_1.empty() || curr_1) || (!s_2.empty() || curr_2))
    {
        while (curr_1)
        {
            s_1.push(curr_1);
            curr_1 = curr_1->l_child;
        }

        while (curr_2)
        {
            s_2.push(curr_2);
            curr_2 = curr_2->l_child;
        }

        Node<int> *temp_1 = s_1.empty() ? nullptr : s_1.top();
        Node<int> *temp_2 = s_2.empty() ? nullptr : s_2.top();

        if (!temp_1)
        {
            std::cout << temp_2->data << ' ';
            s_2.pop();
            curr_2 = temp_2->r_child;
        }
        else if (!temp_2)
        {
            std::cout << temp_1->data << ' ';
            s_1.pop();
            curr_1 = temp_1->r_child;
        }
        else if (temp_1->data < temp_2->data)
        {
            std::cout << temp_1->data << ' ';
            s_1.pop();
            curr_1 = temp_1->r_child;
        }
        else if (temp_2->data < temp_1->data)
        {
            std::cout << temp_2->data << ' ';
            s_2.pop();
            curr_2 = temp_2->r_child;
        }
        else
        {
            std::cout << temp_1->data << ' ';
            s_1.pop();
            s_2.pop();
            curr_1 = temp_1->r_child;
            curr_2 = temp_2->r_child;
        }
    }
    std::cout << '\n';
}

int main()
{
    Binary_Search_Tree<Node<int>> bst_1(6), bst_2(9);
    std::cout << "The first tree is:\n";
    bst_1.display();
    std::cout << "\nThe second tree is:\n";
    bst_2.display();

    merge(bst_1.ROOT, bst_2.ROOT);
}