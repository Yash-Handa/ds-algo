#include <iostream>
#include <queue>

void reverse(std::queue<int> &q)
{
    if (q.empty())
        return;

    int data = q.front();
    q.pop();
    reverse(q);
    q.push(data);
}

int main()
{
    std::queue<int> q;
    q.push(5);
    q.push(10);
    q.push(20);

    reverse(q);

    int i = 1;
    while (!q.empty())
    {
        std::cout << i << ". " << q.front() << '\n';
        q.pop();
        i++;
    }

    return 0;
}