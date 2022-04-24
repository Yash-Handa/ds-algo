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
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 8, 9};
    // int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9};
    // int arr[] = {1, 1, 1, 1, 1, 1};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    if (b == e)
    {
        display_container(b, e);
        return 1;
    }

    int curr = INT32_MIN;
    vector<int>::iterator new_end = b;

    e--;
    while (b <= e)
    {
        if (*b != curr)
        {
            curr = *b;
            *new_end = curr;
            new_end++;
        }
        b++;
    }

    display_container(v.begin(), new_end);

    return 0;
}