/*
? Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only.
? The task is to segregate 0s, 1s, and 2s linked list such that all zeros
? segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.
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

template <class T>
class Linked_List
{
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

    bool sort()
    {
        if (!HEAD || !(HEAD->next))
            return true;

        T *curr_0 = nullptr, *curr_1 = nullptr, *curr_2 = nullptr, *curr = HEAD;
        T *head_0 = nullptr, *head_1 = nullptr, *head_2 = nullptr;
        while (curr)
        {
            switch (curr->data)
            {
            case 0:
                if (!curr_0)
                {
                    curr_0 = curr;
                    head_0 = curr_0;
                }
                else
                {
                    curr_0->next = curr;
                    curr_0 = curr_0->next;
                }
                break;
            case 1:
                if (!curr_1)
                {
                    curr_1 = curr;
                    head_1 = curr_1;
                }
                else
                {
                    curr_1->next = curr;
                    curr_1 = curr_1->next;
                }
                break;
            case 2:
                if (!curr_2)
                {
                    curr_2 = curr;
                    head_2 = curr_2;
                }
                else
                {
                    curr_2->next = curr;
                    curr_2 = curr_2->next;
                }
                break;
            }
            curr = curr->next;
        }

        if (curr_2)
            curr_2->next = nullptr;

        if (head_0)
        {
            HEAD = head_0;
            if (head_1)
            {
                curr_0->next = head_1;
                curr_1->next = head_2;
            }
            else
                curr_0->next = head_2;
        }
        else if (head_1)
        {
            HEAD = head_1;
            curr_1->next = head_2;
        }
        else
            HEAD = head_2;

        return true;
    }
};

int main()
{
    Linked_List<Node<int>> ll;
    int arr[] = {1, 2, 2, 1, 2, 0, 2, 2};
    // int arr[] = {2, 2, 0, 1};
    // int arr[] = {2, 2, 2};
    // int arr[] = {0, 0, 0};
    // int arr[] = {1, 1, 1};

    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    ll.create_from_vector(v);

    cout << "Initial linked list: ";
    ll.display();

    ll.sort();

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}