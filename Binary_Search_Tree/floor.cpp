#include <iostream>
#include <vector>
#include "Binary_Search_Tree_Utility.h"

Node<int> *floor_node(Node<int> *root, int k)
{
    Node<int> *curr = root, *ans = nullptr;

    while (curr)
    {
        if (curr->data == k)
            return curr;
        else if (curr->data > k)
            curr = curr->l_child;
        else
        {
            ans = curr;
            curr = curr->r_child;
        }
    }

    return ans;
}

int main()
{
    std::vector<int> v = {12, 23, 21, 56, 43, 76};
    int k = 50;
    Binary_Search_Tree<Node<int>> bst(v);
    std::cout << "The given tree is:\n";
    bst.display();

    Node<int> *f = floor_node(bst.ROOT, k);

    if (!f)
        std::cout << "The floor of num " << k << " does not exist\n";
    else
        std::cout << "The floor of num " << k << " is " << f->data << '\n';
}