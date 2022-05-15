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

    bool insert_at_pos(int pos, int data)
    {
        T *temp = new T(data);
        if (pos == 1)
        {
            temp->next = HEAD;
            HEAD = temp;
            return true;
        }

        T *curr = HEAD;
        for (int i = 1; i <= pos - 2 && curr != NULL; i++)
            curr = curr->next;

        if (curr == NULL)
        {
            delete temp;
            return false;
        }

        temp->next = curr->next;
        curr->next = temp;
        return true;
    }
};

int main()
{
    Linked_List<Node> ll;
    ll.create_dummy(7);

    cout << "Initial linked list: ";
    ll.display();

    ll.insert_at_pos(3, 777);

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}