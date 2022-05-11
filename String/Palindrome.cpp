#include <iostream>

using namespace std;

template <typename T>
bool is_palindrome(T b, T e)
{
    while (b < e)
    {
        if (*b != *e)
            return false;

        b++;
        e--;
    }
    return true;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;

    string ans = str + " is " + (is_palindrome(str.begin(), str.end() - 1) == true ? "" : "not ") + "a palindrome";
    cout << ans << '\n';
    return 0;
}