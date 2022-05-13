#include <iostream>
#include <vector>

using namespace std;

int len_unique(string &str)
{
    vector<int> prev(128, -1);

    int i = 0, res = 0, size = str.size();
    for (int j = 0; j < size; j++)
    {
        if (prev[str[j]] != -1 && prev[str[j]] >= i)
            i = prev[str[j]] + 1;

        res = max(res, j - i + 1);

        prev[str[j]] = j;
    }

    return res;
}

int main()
{
    string str = "dabacabcdd";

    cout << "Length of longest sub-string with all unique charectors is: " << len_unique(str) << '\n';
    return 0;
}