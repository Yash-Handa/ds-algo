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

    bool delete_last()
    {
        if (HEAD == NULL)
            return false;
        else if (HEAD->next == NULL)
        {
            delete HEAD;
            HEAD = NULL;
            return true;
        }

        T *temp = HEAD;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
        return true;
    }
};

int main()
{
    Linked_List<Node> ll;
    ll.create_dummy(7);
    // ll.create_dummy(1);

    cout << "Initial linked list: ";
    ll.display();

    ll.delete_last();

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}