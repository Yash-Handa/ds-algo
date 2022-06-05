#include <iostream>
#include "Binary_Tree_Utility.h"

int mod_height(Node<int> *head, int &ans)
{
    if (!head)
        return 0;

    int l_height = mod_height(head->l_child, ans);
    int r_height = mod_height(head->r_child, ans);

    ans = std::max(ans, l_height + r_height + 1);

    return std::max(l_height, r_height) + 1;
}

int diameter(Node<int> *head)
{
    int ans = 0;
    mod_height(head, ans);
    return ans;
}

int main()
{
    Binary_Tree<Node<int>> bt(15);
    bt.HEAD->l_child = nullptr;
    std::cout << "The given tree:\n";
    bt.display();

    std::cout << "The diameter of the tree is: " << diameter(bt.HEAD) << '\n';
    return 0;
}