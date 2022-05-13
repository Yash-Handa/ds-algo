/*
? Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
? Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1
? to every character of str2 while preserving the order.
? Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’
*/
#include <iostream>
#include <vector>

using std::cout, std::string, std::vector;

bool is_isomorphic(string &s_1, string &s_2)
{
    int size_1 = s_1.size();
    if (size_1 != s_2.size())
        return false;

    int CHARS = 128;
    vector<bool> check(CHARS, false);
    vector<int> map(CHARS, -1);

    for (int i = 0; i < size_1; i++)
    {
        // charector is seen for the first time in s_1
        if (map[s_1[i]] == -1)
        {
            // corresponding char in s_2 is altready seen
            if (check[s_2[i]] == true)
                return false;

            check[s_2[i]] = true;
            map[s_1[i]] = s_2[i]; // map ASCII of char of s_2 to index of ASCII of char of s_1
        }
        // value seen in s_2 for s_1[i] is not same as value seen for previous occurrence of s_1[i]
        else if (map[s_1[i]] != s_2[i])
            return false;
    }

    return true;
}

int main()
{
    string s_1 = "aab", s_2 = "xxy";
    // string s_1 = "aab", s_2 = "xyx";

    cout << "The strings \"" << s_1 << "\" and \"" << s_2 << "\" are " << (is_isomorphic(s_1, s_2) ? "" : "not ") << "isomorphic\n";
    return 0;
}