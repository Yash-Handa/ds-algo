/*
? Given two numbers represented by two linked lists, write a function that returns Sum list.
? The sum list is linked list representation of addition of two input numbers.
*/
#include <iostream>
#include <vector>

using std::cout, std::string, std::vector;

template <typename T>
struct Node
{
    typedef T data_type;
    data_type data;
    Node *next;
    Node(data_type data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
class Linked_List
{
public:
    T *HEAD;
    typedef typename T::data_type data_type;

    Linked_List()
    {
        HEAD = nullptr;
    }

    void display(string sep = " -> ")
    {
        T *curr = HEAD;
        if (!curr)
        {
            cout << "An Empty Linked List...\n";
            return;
        }

        while (curr->next)
        {
            cout << curr->data << sep;
            curr = curr->next;
        }
        cout << curr->data << '\n';
    }

    bool create_from_vector(vector<data_type> &v)
    {
        if (HEAD)
            return false;

        T *curr = nullptr;
        for (int ele : v)
        {
            if (!curr)
            {
                curr = new T(ele);
                HEAD = curr;
            }
            else
            {
                curr->next = new T(ele);
                curr = curr->next;
            }
        }
        return true;
    }
};

// size of head_1 is smaller than or equals to size of head_2
template <typename T>
T *ll_node_sum(T *head_1, T *head_2, int size_1, int size_2)
{
    if (!(head_1->next) && !(head_2->next))
        return new T(head_1->data + head_2->data);

    T *prev_head = nullptr;
    if (size_1 == size_2)
        prev_head = ll_node_sum(head_1->next, head_2->next, size_1 - 1, size_2 - 1);
    else
        // size_2 is greater than size_1
        prev_head = ll_node_sum(head_1, head_2->next, size_1, size_2 - 1);

    int carry = 0;
    if (prev_head->data > 9)
    {
        prev_head->data %= 10;
        carry = 1;
    }

    T *new_head = nullptr;
    if (size_1 == size_2)
        new_head = new T(head_1->data + head_2->data + carry);
    else
        new_head = new T(head_2->data + carry);

    new_head->next = prev_head;
    return new_head;
}

template <typename T>
T *ll_sum(T *head_1, T *head_2)
{
    if (!head_1)
        return head_2;
    if (!head_2)
        return head_1;

    T *curr = head_1;
    int size_1 = 1;
    while (curr->next)
    {
        curr = curr->next;
        size_1++;
    }

    curr = head_2;
    int size_2 = 1;
    while (curr->next)
    {
        curr = curr->next;
        size_2++;
    }

    T *head_3 = size_1 < size_2 ? ll_node_sum(head_1, head_2, size_1, size_2)
                                : ll_node_sum(head_2, head_1, size_2, size_1);

    if (head_3->data > 9)
    {
        head_3->data %= 10;
        T *temp = new T(1);
        temp->next = head_3;
        head_3 = temp;
    }

    return head_3;
}

int main()
{
    Linked_List<Node<int>> ll_1, ll_2, ll_3;
    // int arr_1[] = {9}, arr_2[] = {8, 7};
    int arr_1[] = {2, 3, 4}, arr_2[] = {3, 4, 5};

    vector<int> v_1(arr_1, arr_1 + sizeof(arr_1) / sizeof(arr_1[0]));
    vector<int> v_2(arr_2, arr_2 + sizeof(arr_2) / sizeof(arr_2[0]));

    ll_1.create_from_vector(v_1);
    ll_2.create_from_vector(v_2);

    cout << "1st linked list: ";
    ll_1.display();

    cout << "2st linked list: ";
    ll_2.display();

    ll_3.HEAD = ll_sum(ll_1.HEAD, ll_2.HEAD);

    cout << "Sum linked list: ";
    ll_3.display();
    return 0;
}