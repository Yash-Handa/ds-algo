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
private:
    T *_reverse(T *head, int k)
    {
        T *curr = head, *prev = NULL, *next = NULL;
        int count = 1;
        while (curr != NULL && count <= 3)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != NULL)
        {
            T *rev_head = _reverse(next, k);
            head->next = rev_head;
        }
        return prev;
    }

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

    bool reverse_in_Groups(int k)
    {
        HEAD = _reverse(HEAD, k);
        return true;
    }
};

int main()
{
    Linked_List<Node> ll;
    ll.create_dummy(8);
    int k = 3;

    cout << "Initial linked list: ";
    ll.display();

    ll.reverse_in_Groups(k);

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}