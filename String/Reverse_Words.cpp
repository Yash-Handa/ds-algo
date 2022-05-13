#include <iostream>

using namespace std;

template <typename T>
void reverse_words(T b, T e)
{
    T begin = b, w_start = b;
    while (b < e)
    {
        if (*b == ' ')
        {
            // reverse each word
            reverse(w_start, b);
            w_start = b + 1;
        }
        b++;
    }

    // reverse last word
    reverse(w_start, e);

    // reverse the whole line
    reverse(begin, e);
}

int main()
{
    string line = "find a job";
    cout << "Original Stirng: " << line << '\n';
    reverse_words(line.begin(), line.end());
    cout << "Result Stirng:   " << line << '\n';
    return 0;
}