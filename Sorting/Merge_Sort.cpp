#include <iostream>
#include <vector>
#include <cmath>

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
void merge(T b, T mid, T e)
{
    vector<int> temp(distance(b, e) + 1);
    T i = b, j = mid + 1, k = temp.begin();
    while (i <= mid && j <= e)
    {
        if (*i <= *j)
        {
            *k = *i;
            i++;
        }
        else
        {
            *k = *j;
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        *k = *i;
        i++;
        k++;
    }

    while (j <= e)
    {
        *k = *j;
        j++;
        k++;
    }

    // copy temp vector to original
    k = temp.begin();
    while (b <= e)
    {
        *b = *k;
        b++;
        k++;
    }
}

template <typename T>
void merge_sort(T b, T e)
{
    if (b < e)
    {
        T mid = b + floor(distance(b, e) / 2);
        merge_sort(b, mid);
        merge_sort(mid + 1, e);
        merge(b, mid, e);
    }
}

int main()
{
    int arr[] = {3, 2, 6, 4, 5, 8, 6, 3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    cout << "Before Sorting: ";
    display_container(b, e);

    merge_sort(b, e - 1);

    cout << "After Sorting:  ";
    display_container(b, e);
    return 0;
}
