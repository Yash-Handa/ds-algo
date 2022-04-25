#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // int arr[] = {6, 8, 8, 6, 6, 6};
    int arr[] = {6, 8, 8, 6};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    int count = 1, maj = *b;
    b++;
    e--;
    while (b <= e)
    {
        if (*b == maj)
            count++;
        else
            count--;

        if (count == 0)
        {
            maj = *b;
            count++;
        }
        b++;
    }

    count = 0;
    b = v.begin();

    while (b <= e)
    {
        if (*b == maj)
            count++;
        b++;
    }

    if (count > v.size() / 2)
        cout << "The majority element is: " << maj << '\n';
    else
        cout << "There is no majority element in the array\n";

    return 0;
}
