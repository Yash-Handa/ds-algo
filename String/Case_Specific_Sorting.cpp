/*
? Given a string S consisting of uppercase and lowercase characters.
? The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string
? had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.
*/
#include <iostream>
#include <vector>

using std::cout, std::string, std::vector, std::sort;

string case_sort(string const &str)
{
    string uppers = "", lowers = "";

    for (char ele : str)
    {
        if (isupper(ele))
            uppers.push_back(ele);
        else
            lowers.push_back(ele);
    }

    sort(uppers.begin(), uppers.end());
    sort(lowers.begin(), lowers.end());

    string ans = "";
    int size = str.size();
    int l = 0, u = 0;
    for (int i = 0; i < size; i++)
    {
        if (isupper(str[i]))
        {
            ans.push_back(uppers[u]);
            u++;
        }
        else
        {
            ans.push_back(lowers[l]);
            l++;
        }
    }

    return ans;
}

int main()
{
    string str = "defRTSersUXI";
    cout << "Original String: " << str << '\n';
    cout << "Sorted String:   " << case_sort(str) << '\n';
    return 0;
}