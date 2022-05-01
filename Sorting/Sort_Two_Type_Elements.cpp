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
void hoare_partition(T b, T e)
{
    T i = b - 1, j = e;
    e--;
    while (true)
    {
        do
        {
            i++;
        } while (*i < 0);

        do
        {
            j--;
        } while (*j >= 0);

        if (j <= i)
            return;

        swap(*i, *j);
    }
}

int main()
{
    int arr[] = {-1, 5, -2, 3, 8, -43, 6, 0};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    cout << "Before Sorting: ";
    display_container(b, e);

    hoare_partition(b, e);

    cout << "After Sorting:  ";
    display_container(b, e);

    return 0;
}