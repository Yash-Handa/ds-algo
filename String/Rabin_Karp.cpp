#include <iostream>

using namespace std;

void rabin_karp(string &text, string &pattern)
{
    int q = 9973; // largest 4 digit prime number, used for modulo
    int d = 128;  // used for weighted hash
    int t_hash = 0, p_hash = 0, t_size = text.size(), p_size = pattern.size();

    // calculate initial value of hashes
    for (int i = 0; i < p_size; i++)
    {
        p_hash = (p_hash * d + pattern[i]) % q;
        t_hash = (t_hash * d + text[i]) % q;
    }

    // calculate d ^ (p_size-1);
    int d_pow = 1;
    for (int i = 1; i < p_size; i++)
        d_pow = (d_pow * d) % q;

    for (int i = 0; i <= t_size - p_size; i++)
    {
        if (p_hash == t_hash)
        {
            // verify that a match is found
            bool found = true;
            for (int j = 0; j < p_size; j++)
                if (pattern[j] != text[i + j])
                {
                    found = false;
                    break;
                }

            if (found)
                cout << i << " ";
        }

        // calculate hash for next text window
        if (i < t_size - p_size)
        {
            t_hash = ((t_hash - text[i] * d_pow) * d + text[i + p_size]) % q;
            if (t_hash < 0)
                t_hash += q;
        }
    }
}

int main()
{
    string text = "ABCEABEFABCD", pattern = "ABCD";
    cout << "The pattern \"" << pattern << "\" is present at indices: ";
    rabin_karp(text, pattern);
    cout << '\n';
    return 0;
}