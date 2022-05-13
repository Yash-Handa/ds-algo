/*
? Given two strings S and P. Find the smallest window in the S consisting of all the characters of P.
*/
#include <iostream>
#include <vector>

using std::cout, std::string, std::vector;

void Minimum_Window(string &str, string &patt)
{
    int CHARS = 128;
    vector<int> str_v(CHARS, 0);
    vector<int> patt_v(CHARS, 0);

    int start = 0, len = INT32_MAX;
    int str_size = str.size(), patt_size = patt.size();

    if (patt_size > str_size)
    {
        cout << "None";
        return;
    }

    for (char ele : patt)
        patt_v[ele]++;

    int i = 0, count = 0;
    for (int j = 0; j < str_size; j++)
    {
        str_v[str[j]]++;

        if (str_v[str[j]] <= patt_v[str[j]])
            count++;

        if (count == patt_size)
        {
            while (patt_v[str[i]] == 0 || str_v[str[i]] > patt_v[str[i]])
            {
                if (str_v[str[i]] > patt_v[str[i]])
                    str_v[str[i]]--;
                i++;
            }

            if (len > j - i + 1)
            {
                len = j - i + 1;
                start = i;
            }
        }
    }

    if (len == INT32_MAX)
        cout << "None";
    else
        cout << str.substr(start, len);
}

int main()
{
    string str = "ADOBECODEBANC", patt = "ABC";

    cout << "Smallest window that contain all character of \"" << patt << "\" : ";
    Minimum_Window(str, patt);
    cout << '\n';
    return 0;
}
