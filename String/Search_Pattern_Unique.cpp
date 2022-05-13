#include <iostream>

using namespace std;

void search_pattern(string &text, string &pattern)
{
    int t_size = text.size(), p_size = pattern.size();
    int i = 0;
    while (i <= t_size - p_size)
    {
        int j = 0;
        while (j < p_size && text[i + j] == pattern[j])
            j++;

        if (j == p_size)
            cout << i << " ";

        if (j == 0)
            i++;
        else
            i += j;
    }
}

int main()
{
    string text = "ABCEABEFABCD", pattern = "ABCD";
    cout << "The pattern \"" << pattern << "\" is present at indices: ";
    search_pattern(text, pattern);
    cout << '\n';
    return 0;
}