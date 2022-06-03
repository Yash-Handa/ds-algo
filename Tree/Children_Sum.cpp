#include <iostream>
#include <vector>
#include "Binary_Tree_Utility.h"

bool children_sum(Node<int> *head)
{
    if (!head)
        return true;

    int sum = 0;
    sum += head->l_child ? head->l_child->data : 0;
    sum += head->r_child ? head->r_child->data : 0;

    return ((sum == 0 || sum == head->data) && children_sum(head->l_child) && children_sum(head->r_child));
}

int main()
{
    std::vector<int> v = {9, 5, 4, 2, 3, 4};
    // std::vector<int> v = {9, 5, 4, 2, 3, 3};
    Binary_Tree<Node<int>> bt(v);
    std::cout << "The given Tree:\n";
    bt.display();

    std::cout << "The tree " << (children_sum(bt.HEAD) ? "" : "does not ") << "follows children sum property\n";
    return 0;
}