#include <iostream>

using std::cout, std::string;

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

    bool create_dummy(int size = 5, int mod = 10)
    {
        if (HEAD != NULL)
            return false;

        srand(time(0));
        T *curr = NULL;
        for (int i = 1; i <= size; i++)
        {
            if (curr == NULL)
            {
                curr = new T(rand() % mod);
                HEAD = curr;
            }
            else
            {
                curr->next = new T(rand() % mod);
                curr = curr->next;
            }
        }
        return true;
    }

    bool sorted_insert(int data)
    {
        T *temp = new T(data);
        if (HEAD == NULL)
        {
            HEAD = temp;
            return true;
        }
        else if (data < HEAD->data)
        {
            temp->next = HEAD;
            HEAD = temp;
            return true;
        }

        T *curr = HEAD;
        while (curr->next != NULL && data > curr->next->data)
            curr = curr->next;

        temp->next = curr->next;
        curr->next = temp;
        return true;
    }
};

int main()
{
    Linked_List<Node> ll;
    int arr[] = {56, 77, 23, 91, 31};

    cout << "Initial linked list: ";
    ll.display();

    for (int &ele : arr)
    {
        ll.sorted_insert(ele);
    }

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}