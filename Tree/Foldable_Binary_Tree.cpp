/*
? Given a binary tree, check if the tree can be folded or not. A tree can be folded
? if left and right subtrees of the tree are structure wise same. An empty tree is considered as foldable.
*/
#include <iostream>
#include "Binary_Tree_Utility.h"

bool are_children_mirror(Node<int> *l_child, Node<int> *r_child)
{
    if (!l_child && !r_child)
        return true;

    if (!l_child || !r_child)
        return false;

    return (are_children_mirror(l_child->l_child, r_child->r_child) &&
            are_children_mirror(l_child->r_child, r_child->l_child));
}

bool is_foldable(Node<int> *head)
{
    if (!head)
        return true;

    return are_children_mirror(head->l_child, head->r_child);
}

int main()
{
    Binary_Tree<Node<int>> bt(6);
    bt.HEAD->l_child->l_child = nullptr;
    std::cout << "The given tree is:\n";
    bt.display();

    std::cout << (is_foldable(bt.HEAD) ? "" : "NOT ") << "foldable\n";
    return 0;
}