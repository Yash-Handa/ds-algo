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
void bubble_sort(T b, T e)
{
    bool swapped = false;
    int i = 0, size = distance(b, e);
    while (i <= size - 2)
    {
        int j = 0;
        swapped = false;
        while (j <= size - i - 2)
        {
            if (*(b + j) > *(b + j + 1))
            {
                int temp = *(b + j);
                *(b + j) = *(b + j + 1);
                *(b + j + 1) = temp;

                swapped = true;
            }
            j++;
        }
        if (swapped == false)
            return;
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

    bubble_sort(b, e);

    cout << "After Sorting:  ";
    display_container(b, e);
    return 0;
}
