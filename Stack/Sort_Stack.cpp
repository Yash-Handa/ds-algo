#include <iostream>
#include <stack>

void insertion_sort(std::stack<int> &s, int data)
{
    if (s.empty() || data > s.top())
        s.push(data);
    else
    {
        int temp = s.top();
        s.pop();
        insertion_sort(s, data);
        s.push(temp);
    }
}

void sort_stack(std::stack<int> &s)
{
    if (s.empty())
        return;

    int data = s.top();
    s.pop();
    sort_stack(s);
    insertion_sort(s, data);
}

int main()
{
    int arr[] = {-3, 14, 18, -5, 30};
    std::stack<int> s, ans;
    for (int ele : arr)
        s.push(ele);

    // sorting using recursion and insertion sort.
    sort_stack(s);

    // s is sorted but to display we need to reverse it.
    while (!s.empty())
    {
        ans.push(s.top());
        s.pop();
    }

    // display
    std::cout << "The sorted stack is: ";
    while (!ans.empty())
    {
        std::cout << ans.top() << " ";
        ans.pop();
    }
    std::cout << '\n';
    return 0;
}