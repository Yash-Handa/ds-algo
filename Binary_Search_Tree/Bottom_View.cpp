#include <iostream>
#include <map>
#include <queue>
#include "Binary_Search_Tree_Utility.h"

void bottom_view(Node<int> *root)
{
    if (!root)
        return;

    std::map<int, int> mp;
    std::queue<std::pair<Node<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto ele = q.front();
        q.pop();

        mp[ele.second] = ele.first->data;

        if (ele.first->l_child)
            q.push({ele.first->l_child, ele.second - 1});

        if (ele.first->r_child)
            q.push({ele.first->r_child, ele.second + 1});
    }

    std::cout << "The bottom view of BST is: ";
    for (const auto &ele : mp)
        std::cout << ele.second << ' ';
    std::cout << '\n';
}

int main()
{
    Binary_Search_Tree<Node<int>> bst(7);
    std::cout << "The given tree is:\n";
    bst.display();

    bottom_view(bst.ROOT);
}