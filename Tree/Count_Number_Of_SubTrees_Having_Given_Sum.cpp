#include <iostream>
#include <vector>
#include "Binary_Tree_Utility.h"

int count(Node<int> *head, int sum, int &ans)
{
    if (!head)
        return 0;

    int curr_sum = head->data + count(head->l_child, sum, ans) + count(head->r_child, sum, ans);

    if (curr_sum == sum)
        ans++;

    return curr_sum;
}

int main()
{
    std::vector<int> v = {5, -10, 3, 9, 8, -4, 7};
    // std::vector<int> v = {1, 2, 3};
    int sum = 7;
    Binary_Tree<Node<int>> bt(v);
    std::cout << "The given tree is:\n";
    bt.display();

    int ans = 0;
    count(bt.HEAD, sum, ans);
    std::cout << "The number of sub-trees with sum " << sum << " are: " << ans << '\n';
    return 0;
}