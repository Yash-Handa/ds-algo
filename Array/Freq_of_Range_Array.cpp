/*
? Given an array A[] of n positive integers which can contain integers from 1 to n
? where elements can be repeated or can be absent from the array.
? Your task is to count the frequency of all elements from 1 to n.
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
    int arr[] = {2, 3, 2, 3, 5};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();
    display_container(b, e);

    e--;
    while (b <= e)
    {
        if (*b <= 0)
        {
            b++;
            continue;
        }

        vector<int>::iterator loc = v.begin() + (*b) - 1;
        if (*loc > 0)
        {
            // first occurrence of the number
            // Replace the number at loc with b
            // no increase in b for this iteration.
            *b = *loc;
            *loc = -1;
        }
        else
        {
            *loc -= 1;
            b++;
        }
    }

    b = v.begin();
    while (b <= e)
    {
        if (*b > 0)
            *b = 0;
        else
            *b = -*(b);
        b++;
    }

    cout << "Frequency of each element is: ";
    display_container(v.begin(), v.end());
    return 0;
}
