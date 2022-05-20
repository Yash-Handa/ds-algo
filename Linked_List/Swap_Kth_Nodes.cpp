/*
? Given a singly linked list of size N, and an integer K.
? You need to swap the Kth node from the beginning and Kth node from the end of the linked list.
? Swap the nodes through the links. Do not change the content of the nodes.
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout, std::string, std::vector, std::unordered_set;

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
    unordered_set<int> s;

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

    bool swap(int k)
    {
        if (!HEAD || !(HEAD->next))
            return true;

        T *curr = HEAD;
        int size = 1;
        while (curr->next)
        {
            size++;
            curr = curr->next;
        }

        if (k > size)
            return true;

        int k_last = size - k + 1;

        if (k == k_last)
            return true;

        T *k_node = HEAD, *prev_k_node = nullptr;
        int count = 1;
        while (count < k)
        {
            prev_k_node = k_node;
            k_node = k_node->next;
            count++;
        }

        T *k_last_node = HEAD, *prev_k_last_node = nullptr;
        count = 1;
        while (count < k_last)
        {
            prev_k_last_node = k_last_node;
            k_last_node = k_last_node->next;
            count++;
        }

        if (prev_k_node)
            prev_k_node->next = k_last_node;

        if (prev_k_last_node)
            prev_k_last_node->next = k_node;

        T *temp = k_node->next;
        k_node->next = k_last_node->next;
        k_last_node->next = temp;

        if (k == 1)
            HEAD = k_last_node;
        if (k == size)
            HEAD = k_node;

        return true;
    }
};

int main()
{
    Linked_List<Node> ll;
    int arr[] = {1, 2, 5, 6, 7, 8, 9, 3, 4};
    int k = 1;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    ll.create_from_vector(v);

    cout << "Initial linked list: ";
    ll.display();

    ll.swap(k);

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}