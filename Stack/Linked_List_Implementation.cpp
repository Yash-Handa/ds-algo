#include <iostream>

using std::cout;

template <typename T>
struct Node
{
    typedef T data_type;
    data_type data;
    Node *next;
    Node(data_type data) : data(data), next(nullptr) {}
};

template <typename data_type>
class Stack
{
private:
    Node<data_type> *HEAD;
    int sz;

public:
    Stack() : HEAD(nullptr), sz(0) {}

    int size()
    {
        return sz;
    }

    bool is_empty()
    {
        return (!HEAD);
    }

    bool push(data_type ele)
    {
        sz++;
        Node<data_type> *temp = new Node<data_type>(ele);
        temp->next = HEAD;
        HEAD = temp;
        return true;
    }

    data_type pop()
    {
        if (is_empty())
            return data_type(INT32_MAX);

        Node<data_type> *temp = HEAD;
        HEAD = HEAD->next;
        sz--;
        data_type ele = temp->data;
        delete temp;
        return ele;
    }

    data_type peek()
    {
        if (is_empty())
            return data_type(INT32_MAX);

        return HEAD->data;
    }
};

int main()
{
    Stack<int> s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout << s.pop() << '\n';
    cout << s.size() << '\n';
    cout << s.peek() << '\n';
    cout << s.is_empty() << '\n';
    return 0;
}