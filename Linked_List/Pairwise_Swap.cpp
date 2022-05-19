#include <iostream>

using std::cout, std::string;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
class Linked_List
{
public:
    T *HEAD;

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

    bool create_dummy(int size = 5, int mod = 10)
    {
        if (HEAD)
            return false;

        srand(time(0));
        T *curr = nullptr;
        for (int i = 1; i <= size; i++)
        {
            if (!curr)
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

    bool pairwise_swap()
    {
        if (!HEAD || !(HEAD->next))
            return true;

        T *prev = HEAD;
        T *curr = HEAD->next->next;
        HEAD = HEAD->next;
        HEAD->next = prev;

        while (curr && curr->next)
        {
            T *next = curr->next->next;
            prev->next = curr->next;
            curr->next->next = curr;

            prev = curr;
            curr = next;
        }

        prev->next = curr;
        return true;
    }
};

int main()
{
    Linked_List<Node> ll;
    ll.create_dummy(7, 100);
    // ll.create_dummy(1);

    cout << "Initial linked list: ";
    ll.display();

    ll.pairwise_swap();

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}