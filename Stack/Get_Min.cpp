#include <iostream>
#include <stack>

template <class T>
class Custom_Stack
{
private:
    std::stack<T> s;
    T min;

public:
    void push(T data)
    {
        if (is_empty())
        {
            min = data;
            s.push(data);
        }
        else if (data <= min)
        {
            s.push(2 * data - min);
            min = data;
        }
        else
            s.push(data);
    }

    void pop()
    {
        T data = s.top();
        if (data <= min)
            min = 2 * min - data;
        s.pop();
    }

    T peek()
    {
        T data = s.top();
        return data <= min ? min : data;
    }

    T get_min()
    {
        return min;
    }

    int size()
    {
        return s.size();
    }

    bool is_empty()
    {
        return s.empty();
    }
};

int main()
{
    Custom_Stack<int> cs;
    cs.push(5);
    cs.push(10);
    cs.push(20);
    cs.push(2);
    cs.push(6);
    cs.push(4);
    cs.pop();
    std::cout << cs.get_min() << '\n';
    cs.pop();
    std::cout << cs.get_min() << '\n';
    cs.push(2);
    cs.pop();
    std::cout << cs.get_min() << '\n';
    cs.push(1);
    std::cout << cs.get_min() << '\n';
    cs.pop();
    std::cout << cs.get_min() << '\n';
    cs.pop();
    std::cout << cs.get_min() << '\n';
    return 0;
}