#include <iostream>
#include "Binary_Tree_Utility.h"

int max_bt(Node<int> *head)
{
    if (!head)
        return INT32_MIN;

    return std::max(std::max(max_bt(head->r_child), max_bt(head->l_child)), head->data);
}

int main()
{
    Binary_Tree<Node<int>> bt(31);
    bt.HEAD->l_child->data = 777;
    std::cout << "The given Tree:\n";
    bt.display();

    std::cout << "Max in the tree: " << max_bt(bt.HEAD) << '\n';
    return 0;
}