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

    bool create_dummy(int size = 5)
    {
        if (HEAD != NULL)
            return false;

        srand(time(0));
        T *curr = NULL;
        for (int i = 1; i <= size; i++)
        {
            if (curr == NULL)
            {
                curr = new T(rand() % size);
                HEAD = curr;
            }
            else
            {
                curr->next = new T(rand() % size);
                curr = curr->next;
            }
        }
        return true;
    }

    bool insert_end(int data)
    {
        T *temp = new T(data);

        if (HEAD == NULL)
        {
            HEAD = temp;
            return true;
        }

        T *curr = HEAD;
        while (curr->next != NULL)
            curr = curr->next;

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

    ll.insert_end(777);

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}