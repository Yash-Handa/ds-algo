/*
? Given a singly linked list of size N, and an integer K.
? You need to swap the Kth node from the beginning and Kth node from the end of the linked list.
? Swap the nodes through the links. Do not change the content of the nodes.
*/
#include <iostream>
#include <vector>

using std::cout, std::string, std::vector;

template <typename T>
struct Node
{
    T data;
    Node *next;
    typedef T D_T;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <typename T>
class Linked_List
{
public:
    T *HEAD;
    typedef typename T::D_T data_type;

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

    bool is_palindrome()
    {
        if (!HEAD || !(HEAD->next))
            return true;

        T *mid = HEAD, *last = HEAD;
        while (last->next && last->next->next)
        {
            mid = mid->next;
            last = last->next->next;
        }

        // now reverse the linked list beyond mid
        T *rev_head = _reverse(mid->next), *head = HEAD;

        // compare elements in 1st half and reverse of 2nd half
        while (rev_head)
        {
            if (rev_head->data != head->data)
                return false;

            rev_head = rev_head->next;
            head = head->next;
        }

        return true;
    }
};

template <typename T>
T *_reverse(T *head)
{
    if (!head || !(head->next))
        return head;

    T *curr = head, *prev = nullptr, *next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{
    Linked_List<Node<char>> ll;
    char arr[] = {'r', 'a', 'd', 'a', 'r'};
    // char arr[] = {'r', 'a', 'd', 'a'};
    vector<char> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    ll.create_from_vector(v);

    cout << "Initial linked list: ";
    ll.display();

    cout << "The linked list is " << (ll.is_palindrome() ? "" : "not ") << "a palindrome\n";
    return 0;
}