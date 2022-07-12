/*
? Given a number K and string str of digits denoting a positive integer,
? build the largest number possible by performing swap operations on the digits of str at most K times.
*/
#include <iostream>

using std::string;

void max_num(string str, string &max_str, int swap, int i)
{
    if (swap == 0)
        return;

    int sz = str.size();
    int mx = str[i];
    for (int j = i + 1; j < sz; j++)
        mx = std::max((char)mx, str[j]);

    if (mx != str[i])
        swap--;

    for (int j = sz - 1; j >= i; j--)
    {
        // do recursive calls for each occurrence mx to check which mx occurrence should be swapped in
        if (str[j] == mx)
        {
            std::swap(str[j], str[i]);

            if (str.compare(max_str) > 0)
                max_str = str;

            max_num(str, max_str, swap, i + 1);

            std::swap(str[j], str[i]);
        }
    }
}

int main()
{
    // string str = "1234567";
    // int swap = 4;

    string str = "4551711527";
    int swap = 3;

    string max_str = str;
    max_num(str, max_str, swap, 0);
    std::cout << "The largest number with " << swap << " swaps is: " << max_str << '\n';
}