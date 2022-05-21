/*
? Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
? Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.
*/
#include <iostream>
#include <vector>

using std::cout, std::string, std::vector;

template <typename T>
struct Node
{
    typedef T T_D;
    T_D data;
    Node *next;
    Node(T_D data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
T *merge(T *head_1, T *head_2)
{
    if (!head_1)
        return head_2;
    if (!head_2)
        return head_1;

    T *i = head_1, *j = head_2, *k = nullptr, *new_head = nullptr;
    if (i->data < j->data)
    {
        k = i;
        i = i->next;
    }
    else
    {
        k = j;
        j = j->next;
    }
    new_head = k;

    while (i && j)
    {
        if (i->data < j->data)
        {
            k->next = i;
            i = i->next;
        }
        else
        {
            k->next = j;
            j = j->next;
        }
        k = k->next;
    }

    if (i)
        k->next = i;
    else
        k->next = j;

    return new_head;
}

template <class T>
class Linked_List
{
private:
    T *_merge_sort(T *head)
    {
        if (!head || !(head->next))
            return head;

        T *mid = find_mid(head);
        T *head_2 = mid->next;
        mid->next = nullptr;

        return merge(_merge_sort(head), _merge_sort(head_2));
    }

public:
    T *HEAD;
    typedef typename T::T_D data_type;

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

    bool merge_sort()
    {
        HEAD = _merge_sort(HEAD);
        return true;
    }

    T *find_mid(T *head)
    {
        if (!head || !(head->next))
            return head;

        T *mid = head, *end = head;
        while (end->next && end->next->next)
        {
            mid = mid->next;
            end = end->next->next;
        }
        return mid;
    }
};

int main()
{
    Linked_List<Node<int>> ll;
    int arr[] = {1, 2, 5, 6, 7, 8, 9, 3, 4};
    int k = 1;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    ll.create_from_vector(v);

    cout << "Initial linked list: ";
    ll.display();

    ll.merge_sort();

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}