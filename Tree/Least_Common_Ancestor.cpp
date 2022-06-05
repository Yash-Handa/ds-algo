/*
? The program finds the least common ancestor if "both the nodes are present"
*/
#include <iostream>
#include <vector>
#include "Binary_Tree_Utility.h"

// works only when both nodes are present. It will not return null if one node is absent
Node<int> *lca(Node<int> *head, int a, int b)
{
    if (!head)
        return nullptr;

    if (head->data == a || head->data == b)
        return head;

    Node<int> *lca_1 = lca(head->l_child, a, b), *lca_2 = lca(head->r_child, a, b);

    if (lca_1 && lca_2)
        return head;

    if (lca_1)
        return lca_1;
    else
        return lca_2;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 0, 0, 4, 5};
    int a = 4, b = 5;
    Binary_Tree<Node<int>> bt(v);
    bt.HEAD->l_child->l_child = nullptr;
    bt.HEAD->l_child->r_child = nullptr;
    std::cout << "The given tree:\n";
    bt.display();

    int ans = lca(bt.HEAD, a, b)->data;
    std::cout << "The least common ancestor of " << a << ", " << b << " is: " << ans << '\n';
    return 0;
}