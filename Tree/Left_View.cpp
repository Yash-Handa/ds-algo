#include <iostream>
#include "Binary_Tree_Utility.h"
#include <queue>

void left_view(Node<int> *head)
{
    if (!head)
        return;

    std::queue<Node<int> *> q;
    q.push(head);

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node<int> *temp = q.front();
            q.pop();

            if (i == 0)
                std::cout << temp->data << " ";

            if (temp->l_child)
                q.push(temp->l_child);
            if (temp->r_child)
                q.push(temp->r_child);
        }
    }
}

int main()
{
    Binary_Tree<Node<int>> bt(31);
    bt.HEAD->l_child->l_child = nullptr;
    std::cout << "The given Tree:\n";
    bt.display();

    std::cout << "Left view of the tree: ";
    left_view(bt.HEAD);
    std::cout << '\n';
    return 0;
}