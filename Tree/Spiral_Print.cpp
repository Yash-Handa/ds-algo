#include <iostream>
#include <stack>
#include "Binary_Tree_Utility.h"

void spiral_print(Node<int> *head)
{
    if (!head)
        return;

    std::stack<Node<int> *> s1, s2;
    s1.push(head);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node<int> *curr = s1.top();
            s1.pop();

            std::cout << curr->data << " ";

            if (curr->l_child)
                s2.push(curr->l_child);
            if (curr->r_child)
                s2.push(curr->r_child);
        }

        while (!s2.empty())
        {
            Node<int> *curr = s2.top();
            s2.pop();

            std::cout << curr->data << " ";

            if (curr->r_child)
                s1.push(curr->r_child);
            if (curr->l_child)
                s1.push(curr->l_child);
        }
    }
}

int main()
{
    Binary_Tree<Node<int>> bt(15);
    std::cout << "The given tree:\n";
    bt.display();

    std::cout << "The spiral print is: ";
    spiral_print(bt.HEAD);
    std::cout << '\n';
    return 0;
}