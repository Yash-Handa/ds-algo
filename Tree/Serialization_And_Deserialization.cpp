#include <iostream>
#include <vector>
#include "Binary_Tree_Utility.h"

void serialization(Node<int> *head, std::vector<int> &v)
{
    if (!head)
    {
        v.push_back(-1);
        return;
    }

    v.push_back(head->data);
    serialization(head->l_child, v);
    serialization(head->r_child, v);
    return;
}

Node<int> *deserialization(std::vector<int> &v, int &i)
{
    if (v[i] == -1)
    {
        i++;
        return nullptr;
    }

    Node<int> *curr = new Node<int>(v[i]);
    i++;
    curr->l_child = deserialization(v, i);
    curr->r_child = deserialization(v, i);
    return curr;
}

int main()
{
    std::vector<int> v;
    Binary_Tree<Node<int>> bt(15);
    bt.HEAD->l_child->r_child = nullptr;
    std::cout << "The given tree:\n";
    bt.display();

    serialization(bt.HEAD, v);
    std::cout << "The serialized tree is: ";
    for (const int &ele : v)
        std::cout << ele << ' ';
    std::cout << '\n';

    Binary_Tree<Node<int>> new_bt(1);
    int i = 0;
    new_bt.HEAD = deserialization(v, i);
    std::cout << "The deserialized tree is:\n";
    new_bt.display();
    return 0;
}