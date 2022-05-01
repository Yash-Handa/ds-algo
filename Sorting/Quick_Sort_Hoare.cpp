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
T hoare(T b, T e)
{
    T i = b - 1, j = e + 1;
    int pivot = *b;
    while (true)
    {
        do
        {
            i++;
        } while (*i < pivot);

        do
        {
            j--;
        } while (*j > pivot);

        if (j <= i)
            return j;

        swap(*j, *i);
    }
    return b;
}

template <typename T>
void quick_sort(T b, T e)
{
    if (b < e)
    {
        T partition = hoare(b, e);
        quick_sort(b, partition);
        quick_sort(partition + 1, e);
    }
}

int main()
{
    int arr[] = {3, 2, 6, 4, 5, 8, 6, 3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    cout << "Before Sorting: ";
    display_container(b, e);

    quick_sort(b, e - 1);

    cout << "After Sorting:  ";
    display_container(b, e);
    return 0;
}
