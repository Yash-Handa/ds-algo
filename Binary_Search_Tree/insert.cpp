#include <iostream>
#include <vector>
#include "Binary_Search_Tree_Utility.h"

Node<int> *insert_node(Node<int> *root, int s)
{
    if (!root)
        return new Node<int>(s);
    else if (root->data > s)
        root->l_child = insert_node(root->l_child, s);
    else if (root->data < s)
        root->r_child = insert_node(root->r_child, s);

    return root;
}

int main()
{
    std::vector<int> v = {13, 45, 23, 78, 98, 45};
    int s = 88;
    // int s = 78;
    // int s = 68;
    Binary_Search_Tree<Node<int>> bst(v);
    std::cout << "The given tree is:\n";
    bst.display();

    bst.ROOT = insert_node(bst.ROOT, s);

    std::cout << "The updated tree is:\n";
    bst.display();
}