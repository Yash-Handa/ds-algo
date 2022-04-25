/*
? Given an array arr[] of size N of positive integers which may have duplicates.
? The task is to find the maximum and second maximum from the array, and both of them should be distinct,
? so If no second max exists, then the second max will be -1.
*/
#include <iostream>
#include <vector>

using namespace std;

void max_s_max(vector<int> &v, int &max, int &s_max)
{
    vector<int>::iterator b = v.begin(), e = v.end();

    if (b + 1 == e)
        return;

    e--;
    b++;

    while (b <= e)
    {
        if (*b > max)
        {
            s_max = max;
            max = *b;
        }
        else if (*b<max && * b> s_max)
            s_max = *b;

        b++;
    }
}

int main()
{
    // int arr[] = {2, 1, 2};
    // int arr[] = {1, 1, 1, 1, 1};
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    int max = *(v.begin()), s_max = -1;
    max_s_max(v, max, s_max);

    cout << "The max is: " << max << " .The second max is: " << s_max << '\n';
    return 0;
}