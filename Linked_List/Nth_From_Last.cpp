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

    int from_last(int pos)
    {
        if (HEAD == NULL)
            return -1;

        T *last = HEAD, *find = NULL;
        int count = 1;
        while (last != NULL)
        {
            if (count == pos)
                find = HEAD;
            else if (count > pos)
                find = find->next;

            last = last->next;
            count++;
        }

        if (find == NULL)
            return -1;
        return find->data;
    }
};

int main()
{
    Linked_List<Node> ll;
    ll.create_dummy(7);
    int n = 3;

    cout << "Initial linked list: ";
    ll.display();

    cout << n << " Element from last: " << ll.from_last(n) << '\n';
    return 0;
}