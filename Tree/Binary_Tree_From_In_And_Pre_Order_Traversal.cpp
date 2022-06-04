#include <iostream>
#include <vector>
#include "Binary_Tree_Utility.h"

int pre_index = 0;
Node<int> *to_BT(std::vector<int> &in, std::vector<int> &pre, int in_b, int in_e)
{
    if (in_b > in_e)
        return nullptr;

    Node<int> *curr = new Node<int>(pre[pre_index]);
    pre_index++;

    int in_index = 0;
    for (int i = in_b; i <= in_e; i++)
        if (in[i] == curr->data)
        {
            in_index = i;
            break;
        }

    curr->l_child = to_BT(in, pre, in_b, in_index - 1);
    curr->r_child = to_BT(in, pre, in_index + 1, in_e);

    return curr;
}

int main()
{
    std::vector<int> in = {4, 2, 6, 5, 7, 1, 8, 9, 3};
    std::vector<int> pre = {1, 2, 4, 5, 6, 7, 3, 8, 9};
    Binary_Tree<Node<int>> bt(1);

    bt.HEAD = to_BT(in, pre, 0, in.size() - 1);
    bt.display();
    return 0;
}