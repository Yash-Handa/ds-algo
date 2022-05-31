/*
? Level Order traversal using queue and two loops
*/
#include <iostream>
#include <vector>
#include <queue>
#include "Binary_Tree_Utility.h"

void level_order(Node<int> *head)
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
            std::cout << temp->data << ' ';

            if (temp->l_child)
                q.push(temp->l_child);

            if (temp->r_child)
                q.push(temp->r_child);
        }
        std::cout << '\n';
    }
}

int main()
{
    std::vector<int> v = {1, 3, 2, 4, 5, 3, 6, 9, 7, 2, 4, 0};
    Binary_Tree<Node<int>> bt;
    bt.Breath_Vise_From_Vector(v);
    bt.HEAD->l_child->r_child = nullptr;
    std::cout << "The given Tree:\n";
    bt.display();

    std::cout << "Level Order traversal:\n";
    level_order(bt.HEAD);
    std::cout << '\n';
    return 0;
}