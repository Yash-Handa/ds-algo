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
    int arr[] = {1, 2, 0, 0, 0, 4, 3, 2, 0, 0, 6, 7};
    // int arr[] = {0, 0, 0, 1, 2, 3, 0, 9, 4};
    // int arr[] = {1, 2, 4, 3, 2, 6, 7};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end(), first_zero = v.end();
    display_container(v.begin(), v.end());

    e--;
    while (b <= e)
    {
        if (*b == 0 && first_zero == v.end())
        {
            first_zero = b;
        }
        else if (*b != 0 && first_zero != v.end())
        {
            *first_zero = *b;
            *b = 0;
            first_zero++;
        }
        b++;
    }

    display_container(v.begin(), v.end());

    return 0;
}