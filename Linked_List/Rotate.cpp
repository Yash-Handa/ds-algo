/*
? Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes,
? where k is a given positive integer smaller than or equal to length of the linked list.
*/
/*
!! There is a better approach for this question:
!!  1. Convert the linked list to circular linked list
!!  2. Move tail by K positions
!!  3. make tail->next as new HEAD and break the circular linked list
*/
#include <iostream>
#include <vector>

using std::cout, std::string, std::vector;

struct Node
{
    int data;
    Node *next;
    Node(int data)
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

    bool create_from_vector(vector<int> &v)
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

    bool rotate(int k)
    {
        if (!HEAD || !(HEAD->next))
            return true;

        T *tail = HEAD;
        int size = 1;
        while (tail->next)
        {
            tail = tail->next;
            size++;
        }
        k = k % size;
        if (k == 0)
            return true;

        T *k_node = HEAD;
        int count = 1;
        while (count < k)
        {
            k_node = k_node->next;
            count++;
        }

        T *k_next_node = k_node->next;
        T *temp_head_1 = reverse_(HEAD, k_node);
        T *temp_head_2 = reverse_(k_next_node, tail);
        HEAD->next = temp_head_2;
        HEAD = temp_head_1;
        tail = k_next_node;

        HEAD = reverse_(HEAD, tail);
        return true;
    }
};

template <typename T>
T *reverse_(T *h, T *t)
{
    if (h == t)
        return h;

    T *curr = h, *prev = nullptr, *next = nullptr;
    while (curr != t)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    return curr;
}

int main()
{
    Linked_List<Node> ll;
    int arr[] = {1, 2, 5, 6, 7, 8, 9, 3, 4};
    int k = 3;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    ll.create_from_vector(v);

    cout << "Initial linked list: ";
    ll.display();

    ll.rotate(k);

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}