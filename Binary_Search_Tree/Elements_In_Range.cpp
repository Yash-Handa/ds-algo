/*
? Given a Binary Search Tree and a range. Find all the numbers in the BST that lie in the given range.
*/
#include <iostream>
#include <vector>
#include "Binary_Search_Tree_Utility.h"

void in_range(Node<int> *root, int l, int u)
{
    if (!root)
        return;

    in_range(root->l_child, l, u);

    if (root->data >= l && root->data <= u)
        std::cout << root->data << ' ';

    in_range(root->r_child, l, u);
}

int main()
{
    std::vector<int> v = {23, 45, 67, 35, 90, 55};
    int l = 35, u = 70;
    Binary_Search_Tree<Node<int>> bst(v);
    std::cout << "The given tree is:\n";
    bst.display();

    std::cout << "The elements in the range [" << l << ", " << u << "] are: ";
    in_range(bst.ROOT, l, u);
    std::cout << '\n';
}