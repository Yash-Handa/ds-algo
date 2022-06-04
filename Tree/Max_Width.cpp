#include <iostream>
#include "Binary_Tree_Utility.h"
#include <queue>

int max_width(Node<int> *head)
{
    if (!head)
        return 0;

    std::queue<Node<int> *> q;
    int ans = 0;

    q.push(head);
    while (!q.empty())
    {
        int sz = q.size();
        ans = std::max(ans, sz);
        for (int i = 0; i < sz; i++)
        {
            Node<int> *curr = q.front();
            q.pop();

            if (curr->l_child)
                q.push(curr->l_child);

            if (curr->r_child)
                q.push(curr->r_child);
        }
    }
    return ans;
}

int main()
{
    Binary_Tree<Node<int>> bt(16);
    bt.HEAD->l_child->r_child = nullptr;
    bt.HEAD->l_child->l_child->r_child = nullptr;
    std::cout << "The given Tree:\n";
    bt.display();

    std::cout << "The maximum nodes at a level are: " << max_width(bt.HEAD) << "\n";
    return 0;
}