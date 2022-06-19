#include <iostream>
#include <map>
#include "Binary_Search_Tree_Utility.h"

void v_s(Node<int> *root, int horiz_dist, std::map<int, int> &mp)
{
    if (!root)
        return;

    mp[horiz_dist] += root->data;
    v_s(root->l_child, horiz_dist - 1, mp);
    v_s(root->r_child, horiz_dist + 1, mp);
}

void vertical_sum(Node<int> *root)
{
    std::map<int, int> mp;
    v_s(root, 0, mp);

    std::cout << "The vertical sums are: ";
    for (const std::pair<int, int> &ele : mp)
    {
        std::cout << ele.second << ' ';
    }
    std::cout << '\n';
}

int main()
{
    Binary_Search_Tree<Node<int>> bst(5);
    std::cout << "The given tree is:\n";
    bst.display();
    vertical_sum(bst.ROOT);
}