#include <iostream>
#include <vector>

using std::cout, std::vector;

template <class T>
class Stack
{
private:
    int cap;
    int top;
    vector<T> arr; // !! NOTE: using vector but it is never resized, i.e, vector won't grow beyond capacity

public:
    Stack(int cap) : cap(cap), top(-1), arr(cap) {}

    int size()
    {
        return top + 1;
    }

    bool is_empty()
    {
        return (top == -1);
    }

    bool push(T ele)
    {
        if (size() == cap)
            return false;

        top++;
        arr[top] = ele;
        return true;
    }

    T pop()
    {
        if (is_empty())
            return T(INT32_MAX);

        T ele = arr[top];
        top--;
        return ele;
    }

    T peek()
    {
        if (is_empty())
            return T(INT32_MAX);

        return arr[top];
    }
};

int main()
{
    Stack<int> s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    cout << s.pop() << '\n';
    cout << s.size() << '\n';
    cout << s.peek() << '\n';
    cout << s.is_empty() << '\n';
    return 0;
}