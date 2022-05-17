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

    bool create_dummy_cycle(int size = 5, int cyc_first = 2, int mod = 10)
    {
        if (HEAD != NULL)
            return false;

        srand(time(0));
        T *curr = NULL, *tail = curr, *cyc_first_node = NULL;
        int count = 1;
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
            tail = curr;

            if (count == cyc_first)
                cyc_first_node = curr;
            count++;
        }

        if (cyc_first > size)
            return true;

        tail->next = cyc_first_node;
        return true;
    }

    void cycle_removal()
    {
        T *slow = HEAD, *fast = HEAD;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // no cycle is present.
        if (fast == NULL || fast->next == NULL)
            return;

        slow = HEAD;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }
};

int main()
{
    Linked_List<Node> ll;
    ll.create_dummy_cycle(7, 3);
    // ll.create_dummy_cycle(7, 7);
    // ll.create_dummy_cycle(7, 13);

    ll.cycle_removal();

    cout << "The cycle has been removed: ";
    ll.display();
    return 0;
}