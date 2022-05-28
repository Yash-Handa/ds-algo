#include <iostream>
#include <vector>

template <class T>
class Queue
{
private:
    int m_cap, m_front, m_size;
    std::vector<T> m_arr; // !! NOTE: using vector but it is never resized, i.e, vector won't grow beyond capacity

    int get_front_index()
    {
        if (is_empty())
            return -1;

        return m_front;
    }

    int get_rear_index()
    {
        if (is_empty())
            return -1;

        return (m_front + m_size - 1) % m_cap;
    }

public:
    Queue(int cap) : m_cap(cap), m_front(0), m_size(0), m_arr(cap) {}

    bool is_empty()
    {
        return (m_size == 0);
    }

    bool is_full()
    {
        return (m_size == m_cap);
    }

    T get_front()
    {
        int idx = get_front_index();
        return idx == -1 ? T(INT32_MAX) : m_arr[idx];
    }

    T get_rear()
    {
        int idx = get_rear_index();
        return idx == -1 ? T(INT32_MAX) : m_arr[idx];
    }

    bool enqueue(T data)
    {
        if (is_full())
            return false;

        int rear = get_rear_index();
        rear = (rear + 1) % m_cap;
        m_arr[rear] = data;
        m_size++;
        return true;
    }

    bool dequeue()
    {
        if (is_empty())
            return false;

        m_front = (m_front + 1) % m_cap;
        m_size--;
        return true;
    }
};

int main()
{
    Queue<int> q(3);
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