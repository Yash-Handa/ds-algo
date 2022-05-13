/*
? Given a string str and another string patt. Find the character in patt that is present at the minimum index in str.
? If no character of patt is present in str then print ‘No character present’.
*/
#include <iostream>
#include <vector>

using std::cout, std::string, std::vector, std::min;

char min_index_char(string &str, string &patt)
{
    int CHARS = 128;
    vector<int> v(CHARS, -1);

    int str_size = str.size();
    for (int i = str_size - 1; i >= 0; i--)
        v[str[i]] = i;

    int mi = INT32_MAX;
    for (char ele : patt)
        if (v[ele] != -1)
            mi = min(mi, v[ele]);

    return mi == INT32_MAX ? '\0' : str[mi];
}

int main()
{
    string str = "Find a job", patt = "aeiou";

    char mc = min_index_char(str, patt);
    if (mc == '\0')
        cout << "No character present\n";
    else
        cout << mc << '\n';

    return 0;
}