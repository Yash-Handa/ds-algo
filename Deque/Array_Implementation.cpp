#include <iostream>
#include <vector>

template <class T>
class Deque
{
private:
    int m_sz, m_cap, m_front;
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

        return (m_front + m_sz - 1) % m_cap;
    }

public:
    Deque(int cap) : m_cap(cap), m_sz(0), m_front(0), m_arr(cap) {}

    int size()
    {
        return m_sz;
    }

    bool is_empty()
    {
        return (m_sz == 0);
    }

    bool is_full()
    {
        return (m_sz == m_cap);
    }

    T get_front()
    {
        int idx = get_front_index();
        if (idx == -1)
            return T(INT32_MAX);

        return m_arr[idx];
    }

    T get_rear()
    {
        int idx = get_rear_index();
        if (idx == -1)
            return T(INT32_MAX);

        return m_arr[idx];
    }

    bool insert_front(T data)
    {
        if (is_full())
            return false;

        m_front = (m_front - 1 + m_cap) % m_cap;
        m_arr[m_front] = data;
        m_sz++;
        return true;
    }

    bool remove_front()
    {
        if (is_empty())
            return false;

        m_front = (m_front + 1) % m_cap;
        m_sz--;
        return true;
    }

    bool insert_rear(T data)
    {
        if (is_full())
            return false;

        m_sz++;
        m_arr[get_rear_index()] = data;
        return true;
    }

    bool remove_rear()
    {
        if (is_empty())
            return false;

        m_sz--;
        return true;
    }
};

int main()
{
    using std::cout;

    Deque<int> d(5);
    d.insert_front(2);
    d.insert_front(1);
    d.insert_rear(3);
    d.insert_rear(4);
    cout << "Front: " << d.get_front() << "  Rear: " << d.get_rear() << '\n';
    d.remove_front();
    cout << "Front: " << d.get_front() << "  Rear: " << d.get_rear() << '\n';
    d.remove_rear();
    cout << "Front: " << d.get_front() << "  Rear: " << d.get_rear() << '\n';
    d.insert_rear(100);
    cout << "Front: " << d.get_front() << "  Rear: " << d.get_rear() << '\n';
    d.remove_front();
    cout << "Front: " << d.get_front() << "  Rear: " << d.get_rear() << '\n';
    return 0;
}