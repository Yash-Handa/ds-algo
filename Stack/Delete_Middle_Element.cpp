/*
? Given a stack with push(), pop(), empty() operations, delete the middle of the stack without
? using any additional data structure.
? Middle: ceil(size_of_stack/2.0)
*/
#include <iostream>
#include <stack>
#include <cmath>

int delete_mid(std::stack<int> &s, int size = 1)
{
    if (s.empty())
        return std::ceil(size / 2.0);

    int data = s.top();
    s.pop();
    int mid = delete_mid(s, size + 1);

    if (size != mid)
        s.push(data);

    return mid;
}

int main()
{
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    delete_mid(s);

    std::cout << "The updated stack is: ";
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << '\n';

    return 0;
}