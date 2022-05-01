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
void dutch_flag_partition(T b, T e)
{
    T window_1 = b, window_2 = b, window_3 = e - 1;
    while (window_2 <= window_3)
    {
        if (*window_2 == 0)
        {
            swap(*window_1, *window_2);
            window_1++;
            window_2++;
        }
        else if (*window_2 == 1)
            window_2++;
        else
        {
            swap(*window_3, *window_2);
            window_3--;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 0, 2, 1, 2, 0, 2, 1, 0};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    cout << "Before Sorting: ";
    display_container(b, e);

    dutch_flag_partition(b, e);

    cout << "After Sorting:  ";
    display_container(b, e);

    return 0;
}