#include <iostream>
#include <vector>

using namespace std;

int leftmost(string &str)
{
    int res = -1;
    vector<bool> CHAR(128, false);

    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (CHAR[str[i]])
            res = i;
        else
            CHAR[str[i]] = true;
    }

    return res;
}

int main()
{
    string str = "abccbd";
    // string str = "abc";

    cout << "Index of leftmost repeating element is: " << leftmost(str) << '\n';
    return 0;
}