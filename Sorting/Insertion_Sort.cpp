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
void insertion_sort(T b, T e)
{
    T i = b + 1;
    while (i < e)
    {
        int key = *i;
        T j = i - 1;
        while (j >= b && *j > key)
        {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
        i++;
    }
}

int main()
{
    int arr[] = {3, 2, 6, 4, 5, 8, 6, 3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    cout << "Before Sorting: ";
    display_container(b, e);

    insertion_sort(b, e);

    cout << "After Sorting:  ";
    display_container(b, e);
    return 0;
}