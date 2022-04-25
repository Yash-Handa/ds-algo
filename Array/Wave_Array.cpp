/*
? Given a sorted array arr[] of distinct integers.
? Sort the array into a wave-like array and return it.
? In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5...
? (considering the increasing lexicographical order).
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

int main()
{
    // int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {2, 4, 7, 8, 9, 10};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();
    display_container(b, e);

    e--;
    b++;
    while (b <= e)
    {
        *b += *(b - 1);
        *(b - 1) = *b - *(b - 1);
        *b -= *(b - 1);
        b += 2;
    }

    display_container(v.begin(), v.end());
    return 0;
}
