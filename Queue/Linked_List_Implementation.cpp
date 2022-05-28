#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
    Node(T data) : data(data), next(nullptr) {}
};

template <class T>
class Queue
{
private:
    Node<T> *HEAD, *TAIL;
    int sz;

public:
    Queue() : HEAD(nullptr), TAIL(nullptr), sz(0) {}

    bool is_empty()
    {
        return (!HEAD);
    }

    int size()
    {
        return sz;
    }

    T get_front()
    {
        return HEAD ? HEAD->data : T(INT32_MAX);
    }

    T get_rear()
    {
        return TAIL ? TAIL->data : T(INT32_MAX);
    }

    bool enqueue(T data)
    {
        Node<T> *temp = new Node(data);
        sz++;
        if (!HEAD)
        {
            HEAD = temp;
            TAIL = temp;
            return true;
        }

        TAIL->next = temp;
        TAIL = TAIL->next;
        return true;
    }

    bool dequeue()
    {
        if (is_empty())
            return false;

        Node<int> *temp = HEAD;
        sz--;
        HEAD = HEAD->next;
        if (!HEAD)
            TAIL = nullptr;

        delete temp;
        return true;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Front: " << q.get_front() << "  Rear: " << q.get_rear() << '\n';
    q.dequeue();
    std::cout << "Front: " << q.get_front() << "  Rear: " << q.get_rear() << '\n';
    q.dequeue();
    std::cout << "Front: " << q.get_front() << "  Rear: " << q.get_rear() << '\n';
    q.enqueue(40);
    std::cout << "Front: " << q.get_front() << "  Rear: " << q.get_rear() << '\n';
    q.dequeue();
    std::cout << "Front: " << q.get_front() << "  Rear: " << q.get_rear() << '\n';
    return 0;
}