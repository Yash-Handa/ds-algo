#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int arr[] = {3, 2, 8, 15, -8};
    int sum = 17;
    unordered_set<int> s;
    string ans = "No";

    for (int ele : arr)
    {
        if (s.find(sum - ele) != s.end())
        {
            ans = "Yes";
            break;
        }
        s.insert(ele);
    }

    cout << "Pair with sum " << sum << " is present ? " << ans << '\n';
    return 0;
}