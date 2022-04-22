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
void reverse_custom(T begin, T end)
{
    if (begin == end)
        return;

    end--;
    while (begin < end)
    {
        *begin += *end;
        *end = *begin - *end;
        *begin -= *end;

        begin++;
        end--;
    }
}

int main()
{
    int arr[] = {5, 8, 10, 12, 15, 17};
    int rot = 2;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "Original array: ";
    display_container(v.begin(), v.end());

    // rotate the first half
    reverse_custom(v.begin(), v.begin() + rot);

    // rotate the second half
    reverse_custom(v.begin() + rot, v.end());

    // rotate the entire vector
    reverse_custom(v.begin(), v.end());

    cout << "Array Rotated by " << rot << ": ";
    display_container(v.begin(), v.end());
    return 0;
}