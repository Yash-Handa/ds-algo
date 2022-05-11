#include <iostream>
#include <vector>

using namespace std;

int leftmost(string &str)
{
    int res = INT32_MAX;
    vector<int> CHAR(128, -1);

    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        if (CHAR[str[i]] == -1)
            CHAR[str[i]] = i;
        else
            CHAR[str[i]] = -2;
    }

    for (int ele : CHAR)
    {
        if (ele >= 0)
            res = min(res, ele);
    }
    return res == INT32_MAX ? -1 : res;
}

int main()
{
    string str = "abccbd";
    string str = "abbacc";

    cout << "Index of leftmost Non Repeating element is: " << leftmost(str) << '\n';
    return 0;
}