#include <iostream>

using namespace std;

template <typename T>
bool is_sub(T b_1, T e_1, T b_2, T e_2)
{
    while (b_1 < e_1 && b_2 < e_2)
    {
        if (*b_1 == *b_2)
            b_2++;
        b_1++;
    }

    if (b_2 == e_2)
        return true;
    return false;
}

int main()
{
    string s_1 = "abcde", s_2 = "ad";
    cout << (is_sub(s_1.begin(), s_1.end(), s_2.begin(), s_2.end()) ? "Yes" : "No") << '\n';
    return 0;
}