#include <iostream>
#include <array>
#include <stack>

using std::cout;

int main()
{
    std::array<int, 6> arr = {60, 10, 20, 15, 35, 70};
    std::stack<int> s;

    cout << "Data: ";
    for (int &ele : arr)
        cout << ele << " ";
    cout << '\n';

    cout << "Span: ";
    for (size_t idx = 0; int &ele : arr)
    {
        while (!s.empty() && arr[s.top()] <= ele)
            s.pop();

        int span = s.empty() ? idx + 1 : idx - s.top();
        cout << span << " ";
        s.push(idx);
        idx++;
    }
    cout << '\n';
    return 0;
}