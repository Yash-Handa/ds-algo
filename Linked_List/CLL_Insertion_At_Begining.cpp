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
class Circular_Linked_List
{
public:
    T *TAIL;

    Circular_Linked_List()
    {
        TAIL = NULL;
    }

    void display(string sep = " -> ")
    {
        if (TAIL == NULL)
        {
            cout << "An Empty Linked List...\n";
            return;
        }

        T *h = TAIL->next;

        while (h != TAIL)
        {
            cout << h->data << sep;
            h = h->next;
        }
        cout << h->data << '\n';
    }

    bool create_dummy(int size = 5, int mod = 10)
    {
        if (TAIL != NULL)
            return false;

        srand(time(0));
        T *curr = NULL, *h = NULL;
        for (int i = 1; i <= size; i++)
        {
            if (curr == NULL)
            {
                curr = new T(rand() % mod);
                h = curr;
            }
            else
            {
                curr->next = new T(rand() % mod);
                curr = curr->next;
            }
            TAIL = curr;
        }
        TAIL->next = h;
        return true;
    }

    bool insert_begin(int data)
    {
        T *temp = new T(data);
        if (TAIL == NULL)
        {
            TAIL = temp;
            TAIL->next = TAIL;
            return true;
        }

        temp->next = TAIL->next;
        TAIL->next = temp;
        return true;
    }
};

int main()
{
    Circular_Linked_List<Node> cll;
    cll.create_dummy(7);

    cout << "Initial linked list: ";
    cll.display();

    cll.insert_begin(777);

    cout << "Updated linked list: ";
    cll.display();
    return 0;
}