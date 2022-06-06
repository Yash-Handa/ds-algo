#include <iostream>
#include <vector>
#include <cmath>
#include "Binary_Tree_Utility.h"

int CBT_size(Node<int> *head)
{
    if (!head)
        return 0;

    Node<int> *curr = head;
    int l_level = 1, r_level = 1;
    while (curr->l_child)
    {
        l_level++;
        curr = curr->l_child;
    }

    curr = head;
    while (curr->r_child)
    {
        r_level++;
        curr = curr->r_child;
    }

    if (l_level == r_level)
        return std::pow(2, l_level) - 1;

    return CBT_size(head->l_child) + CBT_size(head->r_child) + 1;
}

int main()
{
    std::vector<int> v = {2, 3, 4, 3, 5, 4, 6, 5, 4, 6, 3, 4};
    Binary_Tree<Node<int>> bt(v);
    std::cout << "The given tree:\n";
    bt.display();

    std::cout << "Size of the Complete Binary Tree: " << CBT_size(bt.HEAD) << '\n';
    return 0;
}