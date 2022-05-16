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

    bool remove_duplicates()
    {
        if (HEAD == NULL)
            return true;

        T *curr = HEAD;
        while (curr->next != NULL)
        {
            if (curr->data == curr->next->data)
            {
                T *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else
                curr = curr->next;
        }
        return true;
    }
};

int main()
{
    Linked_List<Node> ll;
    int arr[] = {10, 20, 20, 30, 30, 30};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    ll.create_from_vector(v);

    cout << "Initial linked list: ";
    ll.display();

    ll.remove_duplicates();

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}