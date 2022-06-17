#include <iostream>
#include <vector>
#include "Binary_Search_Tree_Utility.h"

int get_successor_key(Node<int> *root)
{
    Node<int> *curr = root;
    while (curr->l_child)
        curr = curr->l_child;
    return curr->data;
}

Node<int> *del_node(Node<int> *root, int del)
{
    if (!root)
        return nullptr;
    else if (root->data > del)
        root->l_child = del_node(root->l_child, del);
    else if (root->data < del)
        root->r_child = del_node(root->r_child, del);
    else
    {
        if (!(root->l_child))
        {
            Node<int> *temp = root->r_child;
            delete root;
            return temp;
        }
        else if (!(root->r_child))
        {
            Node<int> *temp = root->l_child;
            delete root;
            return temp;
        }
        else
        {
            int successor_key = get_successor_key(root->r_child);
            root->data = successor_key;
            root->r_child = del_node(root->r_child, successor_key);
            return root;
        }
    }
    return root;
}

int main()
{
    std::vector<int> v = {23, 43, 56, 22, 76, 49};
    int del = 43;
    Binary_Search_Tree<Node<int>> bst(v);
    std::cout << "The given tree is:\n";
    bst.display();

    bst.ROOT = del_node(bst.ROOT, del);
    std::cout << "The tree after deleting " << del << " is:\n";
    bst.display();
}