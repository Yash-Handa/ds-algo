#include <iostream>

using namespace std;

int main()
{
    string s_1 = "abcd", s_2 = "cdab";
    bool ans = false;

    if (s_1.size() == s_2.size() && (s_1 + s_1).find(s_2) != string::npos)
        ans = true;

    cout << "\"" << s_2 << "\" is " << (ans ? "" : "not ") << "a rotation of \"" << s_1 << "\"\n";
    return 0;
}