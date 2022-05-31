#include <iostream>
#include <vector>
#include "Binary_Tree_Utility.h"

void print_k_level(Node<int> *head, int k)
{
    if (!head)
        return;

    if (k == 0)
    {
        std::cout << head->data << " ";
        return;
    }

    print_k_level(head->l_child, k - 1);
    print_k_level(head->r_child, k - 1);
}

int main()
{
    std::vector<int> v = {1, 3, 2, 4, 5, 3, 6, 9, 7, 2, 4, 0};
    int k = 2;
    Binary_Tree<Node<int>> bt;
    bt.Breath_Vise_From_Vector(v);
    std::cout << "The given Tree:\n";
    bt.display();

    std::cout << "The " << k << " level elements are: ";
    print_k_level(bt.HEAD, k);
    std::cout << '\n';
    return 0;
}