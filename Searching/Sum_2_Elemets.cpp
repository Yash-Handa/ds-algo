#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool has_pair(T b, T e, int sum)
{
    e--;
    while (b < e)
    {
        if (*b + *e == sum)
            return true;
        else if (*b + *e > sum)
            e--;
        else
            b++;
    }
    return false;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int sum = 12;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    if (has_pair(b, e, sum) == true)
        cout << "There exist a pair with sum " << sum << '\n';
    else
        cout << "No pair exist with sum: " << sum << '\n';

    return 0;
}