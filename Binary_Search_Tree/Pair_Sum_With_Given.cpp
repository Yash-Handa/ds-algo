#include <iostream>
#include <unordered_set>
#include <vector>
#include "Binary_Search_Tree_Utility.h"

bool has_pair(Node<int> *root, int sum, std::unordered_set<int> &s)
{
    if (!root)
        return false;

    if (has_pair(root->l_child, sum, s))
        return true;
    else if (s.find(root->data) != s.end())
        return true;
    else
        s.insert(sum - root->data);

    return (has_pair(root->r_child, sum, s));
}

int main()
{
    std::vector<int> v = {12, 54, 67, 34, 89, 45};
    int sum = 88;
    // int sum = 89;
    Binary_Search_Tree<Node<int>> bst(v);
    std::cout << "The given tree is:\n";
    bst.display();

    std::unordered_set<int> s;

    std::cout << "The pair with sum " << sum << " is " << (has_pair(bst.ROOT, sum, s) ? "" : "not ") << "present\n";
}