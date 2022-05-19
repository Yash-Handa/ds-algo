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
        this->next = NULL;
    }
};

template <class T>
class Linked_List
{
public:
    T *HEAD;

    Linked_List()
    {
        HEAD = NULL;
    }

    void display(string sep = " -> ")
    {
        T *curr = HEAD;
        if (curr == NULL)
        {
            cout << "An Empty Linked List...\n";
            return;
        }

        while (curr->next != NULL)
        {
            cout << curr->data << sep;
            curr = curr->next;
        }
        cout << curr->data << '\n';
    }

    bool create_from_vector(vector<int> &v)
    {
        if (HEAD != NULL)
            return false;

        T *curr = NULL;
        for (int ele : v)
        {
            if (curr == NULL)
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

    bool even_odd()
    {
        T *even_head = NULL, *even_tail = NULL, *odd_head = NULL, *odd_tail = NULL, *curr = HEAD;
        while (curr != NULL)
        {
            if (curr->data % 2 == 0)
            {
                if (even_head == NULL)
                {
                    even_head = curr;
                    even_tail = curr;
                }
                else
                {
                    even_tail->next = curr;
                    even_tail = even_tail->next;
                }
            }
            else
            {
                if (odd_head == NULL)
                {
                    odd_head = curr;
                    odd_tail = curr;
                }
                else
                {
                    odd_tail->next = curr;
                    odd_tail = odd_tail->next;
                }
            }
            curr = curr->next;
        }

        // ether the entire list is odd or even or empty
        // so return without doing anything
        if (even_head == NULL || odd_head == NULL)
            return true;

        even_tail->next = odd_head;
        odd_tail->next = NULL;
        HEAD = even_head;
        return true;
    }
};

int main()
{
    Linked_List<Node> ll;
    int arr[] = {19, 20, 21, 32, 30, 35};
    // int arr[] = {10, 20, 20, 30, 30, 30};
    // int arr[] = {11, 21, 21, 31, 31, 31};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    ll.create_from_vector(v);

    cout << "Initial linked list: ";
    ll.display();

    ll.even_odd();

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}