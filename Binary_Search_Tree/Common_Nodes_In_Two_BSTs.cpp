/*
? Given two Binary Search Trees. Find the nodes that are common in both of them,
? ie- find the intersection of the two BSTs.
*/
#include <iostream>
#include <vector>
#include <stack>
#include "Binary_Search_Tree_Utility.h"

void common_nodes(Node<int> *root_1, Node<int> *root_2)
{
    if (!root_1 || !root_2)
        return;

    std::stack<Node<int> *> s_1, s_2;
    Node<int> *curr_1 = root_1, *curr_2 = root_2;

    std::cout << "The common nodes in both the trees are: ";

    while ((!s_1.empty() || curr_1) && (!s_2.empty() || curr_2))
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

        Node<int> *temp_1 = s_1.top();
        Node<int> *temp_2 = s_2.top();

        if (temp_1->data < temp_2->data)
        {
            s_1.pop();
            curr_1 = temp_1->r_child;
        }
        else if (temp_2->data < temp_1->data)
        {
            s_2.pop();
            curr_2 = temp_2->r_child;
        }
        else
        {
            s_1.pop();
            s_2.pop();
            curr_1 = temp_1->r_child;
            curr_2 = temp_2->r_child;
            std::cout << temp_1->data << ' ';
        }
    }

    std::cout << '\n';
}

int main()
{
    std::vector<int> v_1 = {23, 56, 34, 76, 89, 12, 60}, v_2 = {45, 67, 23, 89, 60, 55, 77};
    Binary_Search_Tree<Node<int>> bst_1(v_1), bst_2(v_2);

    std::cout << "The tree 1 is:\n";
    bst_1.display();

    std::cout << "\nThe tree 2 is:\n";
    bst_2.display();

    common_nodes(bst_1.ROOT, bst_2.ROOT);
}