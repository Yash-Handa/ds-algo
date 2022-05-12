#include <iostream>
#include <vector>

using namespace std;

int fact(int num)
{
    int i = 1, res = 1;
    while (i <= num)
    {
        res *= i;
        i++;
    }

    return res;
}

int lex(string &str)
{
    int size = str.size();
    int mul = fact(size); // factorial of size --> size!
    int CHARS = 128;
    vector<int> count(CHARS, 0);

    // put str charectors ascii value in count vector
    for (int i = 0; i < size; i++)
        count[str[i]]++;

    // convert count to prefix sum array
    for (int i = 1; i < CHARS; i++)
        count[i] += count[i - 1];

    int ans = 0; // number of lexicographic patterns smaller than str
    for (int i = 0; i < size; i++)
    {
        mul /= size - i;                 // find smaller factorials 6! -> 5! -> 4!
        int smaller = count[str[i] - 1]; // number of charectors smaller than present charector present on right side of char
        ans += smaller * mul;

        // decrement all the elements after current element in prefix sum array
        // so that only elements present on the right of curr and are smaller is represented by them.
        for (int j = str[i]; j < CHARS; j++)
            count[j]--;
    }

    return ans + 1; // + 1 for the rank of str
}

int main()
{
    string str = "string";
    cout << "The Lexicographic Rank of \"" << str << "\" is: " << lex(str) << '\n';
    return 0;
}