/*
? Given a binary string S. The task is to count the number of substrings that start and end with 1.
? For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.
*/
#include <iostream>

using std::cout, std::string;

int main()
{
    string str = "101011001";
    // string str = "1111";

    int ans = 0, once = 0;
    for (int i = str.size(); i >= 0; i--)
    {
        if (str[i] == '1')
        {
            once++;
            ans += once - 1;
        }
    }

    cout << "Number of substrings that start and end with 1 are: " << ans << '\n';
    return 0;
}