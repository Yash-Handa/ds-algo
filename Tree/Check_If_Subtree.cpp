/*
? Given two binary trees with head reference as T and S having at most N nodes.
? The task is to check if S is present as subtree in T.
? A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "Binary_Tree_Utility.h"

void in_serialize(Node<int> *head, std::vector<int> &v)
{
    if (!head)
    {
        v.push_back(-1);
        return;
    }
    in_serialize(head->l_child, v);
    v.push_back(head->data);
    in_serialize(head->r_child, v);
    return;
}

void pre_serialize(Node<int> *head, std::vector<int> &v)
{
    if (!head)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(head->data);
    pre_serialize(head->l_child, v);
    pre_serialize(head->r_child, v);
    return;
}

bool is_subtree(Node<int> *head_1, Node<int> *head_2)
{
    if (!head_2)
        return true;
    if (!head_1)
        return false;

    std::vector<int> in_1, in_2;
    in_serialize(head_1, in_1);
    in_serialize(head_2, in_2);

    if (std::search(in_2.begin(), in_2.end(), in_1.begin(), in_1.end()) == in_1.end())
        return false;

    std::vector<int> pre_1, pre_2;
    pre_serialize(head_1, pre_1);
    pre_serialize(head_2, pre_2);

    return (std::search(pre_2.begin(), pre_2.end(), pre_1.begin(), pre_1.end()) != pre_1.end());
}

int main()
{
    std::vector<int> v1 = {1, 2, 3, 0, 0, 4}, v2 = {3, 4};
    Binary_Tree<Node<int>> bt_1(v1), bt_2(v2);
    bt_1.HEAD->l_child->l_child = nullptr;
    bt_1.HEAD->l_child->r_child = nullptr;

    std::cout << "The given Tree:\n";
    bt_1.display();

    std::cout << "\nThe given Subtree:\n";
    bt_2.display();

    std::cout << "The given subtree is " << (is_subtree(bt_1.HEAD, bt_2.HEAD) ? "" : "not ") << "a part of the tree\n";
    return 0;
}