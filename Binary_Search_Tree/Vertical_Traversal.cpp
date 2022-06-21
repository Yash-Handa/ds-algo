#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include "Binary_Search_Tree_Utility.h"

void vertical_traversal(Node<int> *root)
{
    if (!root)
        return;

    std::map<int, std::vector<int>> mp;
    std::queue<std::pair<Node<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto ele = q.front();
        q.pop();

        mp[ele.second].push_back(ele.first->data);

        if (ele.first->l_child)
            q.push({ele.first->l_child, ele.second - 1});

        if (ele.first->r_child)
            q.push({ele.first->r_child, ele.second + 1});
    }

    std::cout << "\nThe Vertical Traversal of BST is:\n";
    for (const auto &ele : mp)
    {
        for (const int &e : ele.second)
            std::cout << e << ' ';
        std::cout << '\n';
    }
}

int main()
{
    Binary_Search_Tree<Node<int>> bst(5);
    std::cout << "The given tree is:\n";
    bst.display();

    vertical_traversal(bst.ROOT);
}