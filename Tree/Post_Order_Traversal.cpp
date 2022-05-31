#include <iostream>
#include <vector>

template <typename T>
struct Node
{
    typedef T data_type;
    data_type data;
    Node *l_child, *r_child;
    Node(data_type data) : data(data), l_child(nullptr), r_child(nullptr){};
};

template <class T>
class Binary_Tree
{
public:
    T *HEAD;
    typedef typename T::data_type data_type;

    Binary_Tree() : HEAD(nullptr){};

protected:
    T *insert_level_order(std::vector<data_type> &v, int i)
    {
        if (i >= v.size())
            return nullptr;

        T *curr = new T(v[i]);
        curr->l_child = insert_level_order(v, 2 * i + 1);
        curr->r_child = insert_level_order(v, 2 * i + 2);
        return curr;
    }

    void post_order_traversal(T *head)
    {
        if (!head)
            return;

        post_order_traversal(head->l_child);
        post_order_traversal(head->r_child);
        std::cout << head->data << ' ';
    }

public:
    bool Breath_Vise_From_Vector(std::vector<data_type> &v)
    {
        if (HEAD)
            return false;

        HEAD = insert_level_order(v, 0);
        return true;
    }

    void post_order_traversal()
    {
        post_order_traversal(HEAD);
    }
};

int main()
{
    std::vector<int> v = {10, 20, 30, 40, 50, 60};
    Binary_Tree<Node<int>> bt;
    bt.Breath_Vise_From_Vector(v);

    std::cout << "Post Order Traversal: ";
    bt.post_order_traversal();
    std::cout << '\n';
    return 0;
}