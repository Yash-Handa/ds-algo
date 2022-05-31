#include <iostream>
#include "Binary_Tree_Utility.h"

int tree_size(Node<int> *head)
{
    if (!head)
        return 0;

    return 1 + tree_size(head->l_child) + tree_size(head->r_child);
}

int main()
{
    Binary_Tree<Node<int>> bt(31);
    std::cout << "The given Tree:\n";
    bt.display();

    std::cout << "Size of the tree: " << tree_size(bt.HEAD) << '\n';
    return 0;
}