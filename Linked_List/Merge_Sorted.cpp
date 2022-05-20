#include <iostream>
#include <vector>

using std::cout, std::string, std::vector;

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
};

template <typename T>
T *merge_sort(T *head_1, T *head_2)
{
    if (!head_1)
        return head_2;
    if (!head_2)
        return head_1;

    T *i = head_1, *j = head_2, *k = nullptr, *head_3 = nullptr;

    if (head_1->data < head_2->data)
    {
        k = head_1;
        i = i->next;
    }
    else
    {
        k = head_2;
        j = j->next;
    }
    head_3 = k;

    while (i && j)
    {
        if (i->data < j->data)
        {
            k->next = i;
            i = i->next;
        }
        else
        {
            k->next = j;
            j = j->next;
        }
        k = k->next;
    }

    if (!i)
        k->next = j;
    else
        k->next = i;

    return head_3;
}

int main()
{
    Linked_List<Node> ll_1, ll_2;

    int arr_1[] = {10, 20, 30, 40}, arr_2[] = {5, 15, 17, 18, 35};

    vector<int> v_1(arr_1, arr_1 + sizeof(arr_1) / sizeof(arr_1[0]));
    vector<int> v_2(arr_2, arr_2 + sizeof(arr_2) / sizeof(arr_2[0]));

    ll_1.create_from_vector(v_1);
    ll_2.create_from_vector(v_2);

    cout << "1st linked list:    ";
    ll_1.display();

    cout << "2nd linked list:    ";
    ll_2.display();

    Linked_List<Node> ll_3;
    ll_3.HEAD = merge_sort(ll_1.HEAD, ll_2.HEAD);

    cout << "Merged linked list: ";
    ll_3.display();
    return 0;
}