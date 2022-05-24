#include <iostream>
#include <array>
#include <stack>

using std::cout;

int main()
{
    const size_t sz = 8;
    std::array<int, sz> arr = {5, 15, 10, 8, 6, 12, 9, 18};
    std::stack<int> s, ans;

    cout << "Elements:     ";
    for (int &ele : arr)
        cout << ele << " ";
    cout << '\n';

    cout << "Next Greater: ";
    for (int i = sz - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        int next_greater = s.empty() ? -1 : s.top();
        ans.push(next_greater);
        s.push(arr[i]);
    }

    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << '\n';
    return 0;
}