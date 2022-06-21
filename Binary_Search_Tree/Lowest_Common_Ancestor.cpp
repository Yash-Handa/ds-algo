/*
? Given a Binary Search Tree (with all values unique) and two node values.
? Find the Lowest Common Ancestors of the two nodes in the BST.
*/
#include <iostream>
#include <vector>
#include "Binary_Search_Tree_Utility.h"

// The given algo doesn't take care of case when only one of a or b is present.
// for that you need one more bool parameter (global or reference) to indicate we have seen one node previously.
Node<int> *lca(Node<int> *root, int a, int b)
{
    if (!root)
        return nullptr;

    if (root->data > a && root->data > b)
        return lca(root->l_child, a, b);
    else if (root->data < a && root->data < b)
        return lca(root->r_child, a, b);
    else if (root->data == a || root->data == b)
        return root;
    else
        return root;
}

int main()
{
    std::vector<int> v = {23, 54, 67, 45, 90, 44, 76};
    int a = 45, b = 67;
    Binary_Search_Tree<Node<int>> bst(v);
    std::cout << "The given tree is:\n";
    bst.display();

    Node<int> *ans = lca(bst.ROOT, a, b);
    if (!ans)
        std::cout << "Either " << a << " or " << b << " does not exist";
    else
        std::cout << "The ancestor of " << a << " and  " << b << " is: " << ans->data << '\n';
}