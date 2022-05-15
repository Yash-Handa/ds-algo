#include <iostream>

using std::cout, std::string;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class Doubly_Linked_List
{
public:
    T *HEAD;
    T *TAIL;

    Doubly_Linked_List()
    {
        HEAD = NULL;
        TAIL = NULL;
    }

    void display(string sep = " <-> ")
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
        for (int i = 1; i <= size; i++)
        {
            if (TAIL == NULL)
            {
                TAIL = new T(rand() % mod);
                HEAD = TAIL;
            }
            else
            {
                TAIL->next = new T(rand() % mod);
                TAIL->next->prev = TAIL;
                TAIL = TAIL->next;
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
            TAIL = temp;
            return true;
        }

        TAIL->next = temp;
        temp->prev = TAIL;
        TAIL = temp;
        return true;
    }
};

int main()
{
    Doubly_Linked_List<Node> dll;
    dll.create_dummy(7);

    cout << "Initial linked list: ";
    dll.display();

    dll.insert_end(777);

    cout << "Updated linked list: ";
    dll.display();
    return 0;
}