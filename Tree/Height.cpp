#include <iostream>
#include <vector>
#include "Binary_Tree_Utility.h"

int height(Node<int> *head)
{
    if (!head)
        return 0;

    return std::max(height(head->l_child), height(head->r_child)) + 1;
}

int main()
{
    std::vector<int> v;
    for (int i = 1; i <= 31; i++)
        v.push_back(i % 10);

    Binary_Tree<Node<int>> bt;
    bt.Breath_Vise_From_Vector(v);
    bt.HEAD->l_child->l_child = nullptr;
    bt.HEAD->l_child->r_child = nullptr;
    bt.HEAD->r_child->l_child->l_child = nullptr;
    bt.HEAD->r_child->l_child->r_child = nullptr;
    bt.HEAD->r_child->r_child->r_child = nullptr;
    std::cout << "The given Tree:\n";
    bt.display();

    std::cout << "Height of the tree: " << height(bt.HEAD) << '\n';
    return 0;
}