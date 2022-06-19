#include <iostream>
#include <vector>
#include "Binary_Search_Tree_Utility.h"

bool is_bst(Node<int> *root, int l = INT32_MIN, int u = INT32_MAX)
{
    if (!root)
        return true;

    return (root->data > l && root->data < u &&
            is_bst(root->l_child, l, root->data) &&
            is_bst(root->r_child, root->data, u));
}

int main()
{
    std::vector v = {23, 45, 34, 87, 56, 90, 21};
    Binary_Search_Tree<Node<int>> bst(v);
    bst.ROOT->l_child->r_child->data = 99;
    std::cout << "The given tree is:\n";
    bst.display();

    std::cout << "\nIt is " << (is_bst(bst.ROOT) ? "" : "not ") << "a BST\n";
    return 0;
}