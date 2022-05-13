#include <iostream>
#include <vector>

using namespace std;

bool vec_comp(vector<int> v1, vector<int> v2)
{
    int size = v1.size();
    for (int i = 0; i < size; i++)
        if (v1[i] != v2[i])
            return false;
    return true;
}

void srch_ana(string &text, string &pattern)
{
    vector<int> T_CHAR(128, 0), P_CHAR(128, 0);
    int t_size = text.size(), p_size = pattern.size();

    for (int i = 0; i < p_size; i++)
    {
        T_CHAR[text[i]]++;
        P_CHAR[pattern[i]]++;
    }

    for (int i = 0; i <= t_size - p_size; i++)
    {
        if (vec_comp(T_CHAR, P_CHAR))
            cout << i << " ";

        if (i != t_size - p_size)
        {
            T_CHAR[text[i]]--;
            T_CHAR[text[i + p_size]]++;
        }
    }
}

int main()
{
    string s_1 = "My name is yash", s_2 = "sha";

    cout << "The anagram of \"" << s_2 << "\" is present at: ";
    srch_ana(s_1, s_2);
    cout << '\n';
    return 0;
}