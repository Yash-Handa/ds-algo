/*
? Given an array of names (consisting of lowercase characters) of candidates in an election.
? A candidate name in array represents a vote casted to the candidate.
? Print the name of candidate that received Max votes.
? If there is tie, print lexicographically smaller name.
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    string arr[] = {"john", "johnny", "jackie", "johnny", "john", "jackie", "jamie", "jamie",
                    "john", "johnny", "jamie", "johnny", "john"};
    // string arr[] = {"andy", "blake", "clark"};
    int size = sizeof(arr) / sizeof(arr[0]);

    unordered_map<string, int> m;
    int res = 0;
    string name;

    for (int i = 0; i < size; i++)
    {
        m[arr[i]]++;
        int count = m[arr[i]];

        if (count > res)
        {
            res = count;
            name = arr[i];
        }
        else if (count == res && lexicographical_compare(arr[i].begin(), arr[i].end(), name.begin(), name.end()))
            name = arr[i];
    }

    cout << name << " " << res << '\n';
    return 0;
}