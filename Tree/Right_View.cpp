#include <iostream>
#include "Binary_Tree_Utility.h"
#include <queue>

void _rv(Node<int> *head, int level, int &max_level)
{
    if (!head)
        return;

    if (level > max_level)
    {
        std::cout << head->data << ' ';
        max_level = level;
    }

    _rv(head->r_child, level + 1, max_level);
    _rv(head->l_child, level + 1, max_level);
}

void right_view(Node<int> *head)
{
    int level = 0, max_level = -1;
    _rv(head, level, max_level);
}

int main()
{
    Binary_Tree<Node<int>> bt(31);
    bt.HEAD->r_child->r_child = nullptr;
    std::cout << "The given Tree:\n";
    bt.display();

    std::cout << "Right view of the tree: ";
    right_view(bt.HEAD);
    std::cout << '\n';
    return 0;
}