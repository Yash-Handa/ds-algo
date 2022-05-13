#include <iostream>
#include <vector>

using namespace std;

bool is_anagram(string &s_1, string &s_2)
{
    if (s_1.size() != s_2.size())
        return false;

    vector<int> CHAR(128, 0);
    for (int i = 0; i < s_1.size(); i++)
    {
        CHAR[s_1[i]]++;
        CHAR[s_2[i]]--;
    }

    for (int ele : CHAR)
        if (ele != 0)
            return false;

    return true;
}

int main()
{
    string s_1 = "aabca", s_2 = "acaba";
    cout << s_1 << " and " << s_2 << " are " << (is_anagram(s_1, s_2) ? "" : "not ") << "anagrams\n";
    return 0;
}