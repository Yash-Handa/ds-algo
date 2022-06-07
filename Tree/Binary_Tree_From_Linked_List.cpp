/*
? Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
? Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i,
? its left, and right children are stored at position 2*i+1, 2*i+2 respectively.
*/
#include <iostream>
#include <vector>
#include <queue>
#include "Binary_Tree_Utility.h"

template <typename T>
struct LL_Node
{
    typedef T data_type;
    data_type data;
    LL_Node *next;
    LL_Node(data_type data) : data(data), next(nullptr) {}
};

Node<int> *BT_from_LL(LL_Node<int> *head)
{
    Node<int> *root = nullptr;
    if (!head)
        return root;

    std::queue<Node<int> *> q;
    root = new Node<int>(head->data);
    q.push(root);
    LL_Node<int> *ll_curr = head;
    while (ll_curr)
    {
        Node<int> *tree_curr = q.front();
        q.pop();

        if (!ll_curr->next)
            break;

        ll_curr = ll_curr->next;
        Node<int> *temp = new Node<int>(ll_curr->data);
        q.push(temp);
        tree_curr->l_child = temp;

        if (!ll_curr->next)
            break;

        ll_curr = ll_curr->next;
        temp = new Node<int>(ll_curr->data);
        q.push(temp);
        tree_curr->r_child = temp;
    }

    return root;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    LL_Node<int> *ll_head = nullptr, *curr = nullptr;
    for (const int &ele : v)
    {
        if (!ll_head)
        {
            ll_head = new LL_Node<int>(ele);
            curr = ll_head;
        }
        else
        {
            curr->next = new LL_Node<int>(ele);
            curr = curr->next;
        }
    }

    std::cout << "The given linked list is: ";
    curr = ll_head;
    while (curr->next)
    {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << curr->data << '\n';

    Binary_Tree<Node<int>> bt(1);
    bt.HEAD = BT_from_LL(ll_head);
    std::cout << "The constructed tree is:\n";
    bt.display();
    return 0;
}