/*
? Write a function that returns all permutations of a given list.
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void display_container(T start, T end, string seperator = ",")
{
    if (start == end)
    {
        cout << "AN Empty container....\n";
        return;
    }
    end--;
    while (start != end)
    {
        cout << *start << " " << seperator << " ";
        start++;
    }
    cout << *start << '\n';
}

template <typename T>
void all_perms(vector<T> &suffix, vector<T> &prefix)
{
    if (suffix.empty())
    {
        // display the prefix vector
        display_container(prefix.begin(), prefix.end());
    }

    for (int i = 0; i < suffix.size(); i++)
    {
        vector<T> new_suffix(suffix.begin(), suffix.end());
        vector<T> new_prefix(prefix.begin(), prefix.end());

        new_suffix.erase(new_suffix.begin() + i);
        new_prefix.push_back(suffix[i]);

        all_perms(new_suffix, new_prefix);
    }
}

int main()
{
    unsigned int size;
    vector<int> input;
    cout << "Number of inputs: ";
    cin >> size;
    int i = 0;
    while (i != size)
    {
        int temp;
        cout << "Enter " << i + 1 << " number: ";
        cin >> temp;
        input.push_back(temp);
        i++;
    }

    cout << "Possible permutations are:\n";
    vector<int> prefix;

    // Sample code for char input
    // char arr[] = {'a', 'b', 'c'};
    // vector<char> input(arr, arr + sizeof(arr) / sizeof(arr[0]));
    // vector<char> prefix;

    all_perms(input, prefix);
    return 0;
}