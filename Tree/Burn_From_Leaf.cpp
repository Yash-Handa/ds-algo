#include <iostream>
#include <vector>
#include "Binary_Tree_Utility.h"

int _burnout(Node<int> *head, int leaf, int &ancestor_dist, int &ans)
{
    if (!head)
        return 0;

    if (head->data == leaf)
    {
        ancestor_dist = 0;
        return 1;
    }

    int l_ancestor_dist = -1, r_ancestor_dist = -1;
    int l_height = _burnout(head->l_child, leaf, l_ancestor_dist, ans);
    int r_height = _burnout(head->r_child, leaf, r_ancestor_dist, ans);

    if (l_ancestor_dist != -1)
    {
        ancestor_dist = l_ancestor_dist + 1;
        ans = std::max(ans, ancestor_dist + r_height);
    }

    if (r_ancestor_dist != -1)
    {
        ancestor_dist = r_ancestor_dist + 1;
        ans = std::max(ans, ancestor_dist + l_height);
    }

    return std::max(l_height, r_height) + 1;
}

int burnout(Node<int> *head, int leaf)
{
    int ancestor_dist = -1, ans = 0;
    _burnout(head, leaf, ancestor_dist, ans);
    return ans;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 0, 0, 4, 5};
    int leaf = 4;
    Binary_Tree<Node<int>> bt(v);
    bt.HEAD->l_child->l_child = nullptr;
    bt.HEAD->l_child->r_child = nullptr;
    std::cout << "The given tree:\n";
    bt.display();

    std::cout << "Required time to burn the entire tree from leaf " << leaf << " is: " << burnout(bt.HEAD, leaf) << " unit\n";
    return 0;
}