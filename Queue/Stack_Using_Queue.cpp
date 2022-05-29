#include <iostream>
#include <queue>

template <class T>
class Stack
{
private:
    std::queue<T> base_queue, aux_queue;

public:
    int size()
    {
        return base_queue.size();
    }

    bool is_empty()
    {
        return base_queue.empty();
    }

    T top()
    {
        return base_queue.front();
    }

    void pop()
    {
        base_queue.pop();
    }

    void push(T data)
    {
        while (!base_queue.empty())
        {
            aux_queue.push(base_queue.front());
            base_queue.pop();
        }

        base_queue.push(data);

        while (!aux_queue.empty())
        {
            base_queue.push(aux_queue.front());
            aux_queue.pop();
        }
    }
};

int main()
{
    using std::cout;

    Stack<int> s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout << s.top() << '\n';
    s.pop();
    cout << s.size() << '\n';
    cout << s.top() << '\n';
    cout << s.is_empty() << '\n';
    return 0;
}