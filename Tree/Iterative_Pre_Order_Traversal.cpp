#include <iostream>
#include <stack>
#include "Binary_Tree_Utility.h"

void pre_order(Node<int> *head)
{
    std::stack<Node<int> *> s;
    Node<int> *curr = head;
    while (curr || !s.empty())
    {
        while (curr)
        {
            std::cout << curr->data << ' ';
            s.push(curr);
            curr = curr->l_child;
        }

        curr = s.top()->r_child;
        s.pop();
    }
}

int main()
{
    Binary_Tree<Node<int>> bt(15);
    bt.HEAD->l_child->r_child = nullptr;
    std::cout << "The given tree:\n";
    bt.display();

    std::cout << "The Pre-order traversal is: ";
    pre_order(bt.HEAD);
    std::cout << '\n';
    return 0;
}