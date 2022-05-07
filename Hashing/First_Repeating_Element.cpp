/*
? Given an array arr[] of size N, find the first repeating element.
? The element should occurs more than once and the index of its first occurrence should be the smallest.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int arr[] = {1, 5, 3, 4, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> m;

    int min_rep_ind = size;
    for (int i = size - 1; i >= 0; i--)
    {
        if (m.find(arr[i]) != m.end())
            min_rep_ind = i;

        m[arr[i]] = i;
    }

    cout << "The first repeated element is " << arr[min_rep_ind] << " at index " << min_rep_ind << '\n';
    return 0;
}