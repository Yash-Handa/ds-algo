#include <iostream>
#include <vector>
#include "Binary_Search_Tree_Utility.h"

void fix_bst(Node<int> *root, Node<int> *&prev, Node<int> *&first, Node<int> *&second)
{
    if (!root)
        return;

    fix_bst(root->l_child, prev, first, second);

    if (prev && root->data < prev->data)
    {
        if (!first)
            first = prev;
        second = root;
    }

    prev = root;
    fix_bst(root->r_child, prev, first, second);
}

int main()
{
    std::vector v = {23, 45, 34, 87, 56, 90, 21};
    Binary_Search_Tree<Node<int>> bst(v);
    bst.ROOT->l_child->data = 56;
    bst.ROOT->r_child->l_child->data = 23;
    std::cout << "The given tree is:\n";
    bst.display();

    Node<int> *prev = nullptr, *first = nullptr, *second = nullptr;
    fix_bst(bst.ROOT, prev, first, second);

    std::cout << "Ther nodes to be swapped are: " << first->data << " and " << second->data << '\n';
}