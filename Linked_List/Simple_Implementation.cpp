#include <iostream>

using std::cout, std::string;

template <typename T>
void Display_Linked_List(T head, string sep = " -> ")
{
    if (head == NULL)
    {
        cout << "An Empty Linked List...\n";
        return;
    }

    while (head->next != NULL)
    {
        cout << head->data << sep;
        head = head->next;
    }
    cout << head->data << '\n';
}

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int main()
{
    int arr[] = {2, 5, 4, 7, 3};

    Node *curr = NULL, *head = NULL;
    for (int &ele : arr)
    {
        if (curr == NULL)
        {
            curr = new Node(ele);
            head = curr;
        }
        else
        {
            curr->next = new Node(ele);
            curr = curr->next;
        }
    }

    Display_Linked_List(head);
    return 0;
}