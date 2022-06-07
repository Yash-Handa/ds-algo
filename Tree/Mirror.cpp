/*
? Given a Binary Tree, convert it into its mirror.
*/
#include <iostream>
#include "Binary_Tree_Utility.h"

Node<int> *mirror(Node<int> *head)
{
    if (!head)
        return nullptr;

    Node<int> *temp = head->l_child;
    head->l_child = mirror(head->r_child);
    head->r_child = mirror(temp);

    return head;
}

int main()
{
    Binary_Tree<Node<int>> bt(5);
    std::cout << "The given Tree:\n";
    bt.display();

    bt.HEAD = mirror(bt.HEAD);
    std::cout << "The mirror Tree:\n";
    bt.display();
    return 0;
}