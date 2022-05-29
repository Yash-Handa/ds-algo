#include <iostream>
#include <stack>

template <class T>
class Queue
{
private:
    std::stack<T> base_stack, aux_stack;

public:
    int size()
    {
        return base_stack.size();
    }

    bool is_empty()
    {
        return base_stack.empty();
    }

    void push(T data)
    {
        base_stack.push(data);
    }

    T pop()
    {
        while (!base_stack.empty())
        {
            aux_stack.push(base_stack.top());
            base_stack.pop();
        }

        T data = aux_stack.top();
        aux_stack.pop();

        while (!aux_stack.empty())
        {
            base_stack.push(aux_stack.top());
            aux_stack.pop();
        }
        return data;
    }
};

int main()
{
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    std::cout << q.pop() << '\n';
    std::cout << q.pop() << '\n';
    q.push(40);
    std::cout << q.pop() << '\n';
    return 0;
}