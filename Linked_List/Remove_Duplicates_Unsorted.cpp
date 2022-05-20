#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout, std::string, std::vector, std::unordered_set;

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
    unordered_set<int> s;

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

    bool create_from_vector(vector<int> &v)
    {
        if (HEAD)
            return false;

        T *curr = nullptr;
        for (int ele : v)
        {
            if (!curr)
            {
                curr = new T(ele);
                HEAD = curr;
            }
            else
            {
                curr->next = new T(ele);
                curr = curr->next;
            }
        }
        return true;
    }

    bool remove_duplicates()
    {
        if (!HEAD || !(HEAD->next))
            return true;

        s.insert(HEAD->data);
        T *curr = HEAD;
        while (curr && curr->next)
        {
            if (s.find(curr->next->data) == s.end())
            {
                s.insert(curr->next->data);
                curr = curr->next;
            }
            else
            {
                T *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
        }
        return true;
    }
};

int main()
{
    Linked_List<Node> ll;
    // int arr[] = {5, 2, 2, 4};
    int arr[] = {2, 2, 2, 2, 2};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    ll.create_from_vector(v);

    cout << "Initial linked list: ";
    ll.display();

    ll.remove_duplicates();

    cout << "Updated linked list: ";
    ll.display();
    return 0;
}