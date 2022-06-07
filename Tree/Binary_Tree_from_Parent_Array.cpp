/*
? Given an array of size N that can be used to represents a tree. The array indexes are values in tree nodes and array
? values give the parent node of that particular index (or node).
? The value of the root node index would always be -1 as there is no parent for root.
? Construct the standard linked representation of Binary Tree from this array representation.
*/
#include <iostream>
#include <vector>
#include "Binary_Tree_Utility.h"

Node<int> *v_to_bt(std::vector<int> &v)
{
    int sz = v.size();
    std::vector<Node<int> *> tree_v(sz);
    for (int i = 0; i < sz; i++)
        tree_v[i] = new Node(i);

    Node<int> *head = nullptr;
    for (int i = 0; i < sz; i++)
    {
        if (v[i] == -1)
        {
            head = tree_v[i];
            continue;
        }

        Node<int> *curr = tree_v[v[i]];

        if (!(curr->l_child))
            curr->l_child = tree_v[i];
        else
            curr->r_child = tree_v[i];
    }
    return head;
}

int main()
{
    std::vector<int> v = {-1, 0, 0, 1, 1, 3, 5};
    Binary_Tree<Node<int>> bt(1);
    bt.HEAD = v_to_bt(v);
    std::cout << "The constructed tree is:\n";
    bt.display();
    return 0;
}