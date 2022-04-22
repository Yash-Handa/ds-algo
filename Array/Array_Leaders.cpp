#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {5, 3, 20, 15, 8, 3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();
    e--;
    int max = -1;

    while (b != e)
    {
        if (*e > max)
        {
            max = *e;
            cout << max << ", ";
        }
        e--;
    }

    if (*e > max)
        cout << *e << '\n';

    return 0;
}