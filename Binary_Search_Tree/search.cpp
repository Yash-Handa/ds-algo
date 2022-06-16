#include <iostream>
#include <vector>
#include "Binary_Search_Tree_Utility.h"

bool is_present(Node<int> *root, int s)
{
    Node<int> *curr = root;
    while (curr)
    {
        if (curr->data == s)
            return true;
        else if (curr->data > s)
            curr = curr->l_child;
        else
            curr = curr->r_child;
    }
    return false;
}

int main()
{
    std::vector<int> v = {13, 45, 23, 78, 98, 45};
    int s = 78;
    // int s = 88;
    Binary_Search_Tree<Node<int>> bst(v);
    std::cout << "The given tree is:\n";
    bst.display();

    std::cout << "The number " << s << " is " << (is_present(bst.ROOT, s) ? "" : "not ") << "present\n";
}