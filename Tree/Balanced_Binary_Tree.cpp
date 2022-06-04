#include <iostream>
#include "Binary_Tree_Utility.h"

int is_balanced(Node<int> *head)
{
    if (!head)
        return 0;

    // check if the left sub tree is balanced or not
    int l_height = is_balanced(head->l_child);
    if (l_height == -1)
        return -1;

    // check if the right sub tree is balanced or not
    int r_height = is_balanced(head->r_child);
    if (r_height == -1)
        return -1;

    // check if the current tree is balanced or not
    if (abs(r_height - l_height) > 1)
        return -1;

    // return height of the tree
    return std::max(l_height, r_height) + 1;
}

int main()
{
    Binary_Tree<Node<int>> bt(8);
    bt.HEAD->l_child->r_child = nullptr;
    bt.HEAD->l_child->l_child->r_child = nullptr;
    std::cout << "The given Tree:\n";
    bt.display();

    std::cout << "The tree is " << (is_balanced(bt.HEAD) != -1 ? "" : "not ") << "balanced\n";
    return 0;
}