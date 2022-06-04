#include <iostream>
#include "Binary_Tree_Utility.h"

Node<int> *prev = nullptr;

Node<int> *BT_to_DLL(Node<int> *root)
{
    if (!root)
        return root;

    Node<int> *head = BT_to_DLL(root->l_child);

    if (!prev)
        head = root;
    else
    {
        root->l_child = prev;
        prev->r_child = root;
    }
    prev = root;
    BT_to_DLL(root->r_child);

    return head;
}

int main()
{
    Binary_Tree<Node<int>> bt(15);
    std::cout << "The given Tree:\n";
    bt.display();

    Node<int> *DLL_HEAD = BT_to_DLL(bt.HEAD);
    std::cout << "The converted Doubly Linked List is: ";
    Node<int> *curr = DLL_HEAD;
    while (curr->r_child)
    {
        std::cout << curr->data << " <-> ";
        curr = curr->r_child;
    }
    std::cout << curr->data << '\n';
    return 0;
}