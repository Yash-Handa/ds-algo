/*
? Given a binary tree, connect the nodes that are at same level.
? You'll be given an addition nextRight pointer for the same.
? Initially, all the nextRight pointers point to garbage values.
? Your function should set these pointers to point next right for each node.
*/
#include <iostream>
#include <queue>
#include "Binary_Tree_Utility.h"

template <typename T>
struct Mod_Node
{
    typedef T data_type;
    data_type data;
    Mod_Node *l_child, *r_child, *next_right;
    Mod_Node(data_type data) : data(data), l_child(nullptr), r_child(nullptr), next_right(nullptr){};
};

void connect_nodes(Mod_Node<int> *head)
{
    if (!head)
        return;

    std::queue<Mod_Node<int> *> q;
    q.push(head);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Mod_Node<int> *temp = q.front();
            q.pop();

            if (temp->l_child)
                q.push(temp->l_child);

            if (temp->r_child)
                q.push(temp->r_child);

            if (i < sz - 1)
                temp->next_right = q.front();
        }
    }
}

int main()
{
    Binary_Tree<Mod_Node<int>> bt(15);
    std::cout << "The given Tree:\n";
    bt.display();

    connect_nodes(bt.HEAD);


    std::cout << "Connected levels are:\n";
    Mod_Node<int> *curr_level = bt.HEAD;
    while (curr_level)
    {
        Mod_Node<int> *curr = curr_level;
        while (curr)
        {
            std::cout << curr->data << " ";
            curr = curr->next_right;
        }
        std::cout << '\n';
        curr_level = curr_level->l_child;
    }
    return 0;
}