#include <iostream>
#include <array>
#include <stack>

using std::cout;

int main()
{
    std::array<int, 5> arr = {20, 30, 10, 5, 15};
    std::stack<int> s;

    cout << "Elements:     ";
    for (int &ele : arr)
        cout << ele << " ";
    cout << '\n';

    cout << "Prev Greater: ";
    for (int &ele : arr)
    {
        while (!s.empty() && s.top() <= ele)
            s.pop();

        int span = s.empty() ? -1 : s.top();
        cout << span << " ";
        s.push(ele);
    }
    cout << '\n';
    return 0;
}