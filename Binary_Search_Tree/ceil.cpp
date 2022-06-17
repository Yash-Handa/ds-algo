#include <iostream>
#include <vector>
#include "Binary_Search_Tree_Utility.h"

Node<int> *ceil_node(Node<int> *root, int k)
{
    Node<int> *curr = root, *ans = nullptr;

    while (curr)
    {
        if (curr->data == k)
            return curr;
        else if (curr->data < k)
            curr = curr->r_child;
        else
        {
            ans = curr;
            curr = curr->l_child;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> v = {12, 23, 21, 56, 43, 76};
    int k = 50;
    // int k = 100;
    Binary_Search_Tree<Node<int>> bst(v);
    std::cout << "The given tree is:\n";
    bst.display();

    Node<int> *c = ceil_node(bst.ROOT, k);

    if (!c)
        std::cout << "The ceil of num " << k << " does not exist\n";
    else
        std::cout << "The ceil of num " << k << " is " << c->data << '\n';
}