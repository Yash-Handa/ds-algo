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

    int search(int data)
    {
        T *curr = HEAD;
        int pos = 1;
        while (curr != NULL)
        {
            if (curr->data == data)
                return pos;

            curr = curr->next;
            pos++;
        }
        return -1;
    }
};

int main()
{
    Linked_List<Node> ll;
    ll.HEAD = new Node(10);
    ll.HEAD->next = new Node(20);
    ll.HEAD->next->next = new Node(30);
    ll.HEAD->next->next->next = new Node(40);

    int find = 30;
    // int find = 777;

    cout << "Initial linked list: ";
    ll.display();

    cout << find << " is present at position: " << ll.search(find) << '\n';
    return 0;
}