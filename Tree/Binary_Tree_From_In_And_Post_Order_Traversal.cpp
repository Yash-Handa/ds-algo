#include <iostream>
#include <vector>
#include "Binary_Tree_Utility.h"

Node<int> *_to_BT(std::vector<int> &in, std::vector<int> &post, int in_start, int in_end, int &post_index)
{
    if (in_start > in_end)
        return nullptr;

    Node<int> *curr = new Node<int>(post[post_index]);
    post_index--;

    int sz = in.size(), i;
    for (i = 0; i < sz; i++)
        if (in[i] == curr->data)
            break;

    curr->r_child = _to_BT(in, post, i + 1, in_end, post_index);
    curr->l_child = _to_BT(in, post, in_start, i - 1, post_index);

    return curr;
}

Node<int> *to_BT(std::vector<int> &in, std::vector<int> &post)
{
    if (!in.size())
        return nullptr;

    int post_index = post.size() - 1;
    return _to_BT(in, post, 0, in.size() - 1, post_index);
}

int main()
{
    std::vector<int> in = {4, 8, 2, 5, 1, 6, 3, 7};
    std::vector<int> post = {8, 4, 5, 2, 6, 7, 3, 1};
    Binary_Tree<Node<int>> bt(1);

    bt.HEAD = to_BT(in, post);
    std::cout << "The constructed tree is:\n";
    bt.display();
    return 0;
}