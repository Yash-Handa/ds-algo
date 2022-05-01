#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1, 5, 3, 12, 6, 7};
    int k = 3;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    int res = INT32_MAX;
    sort(b, e);
    e--;
    while (b < e - k + 1)
    {
        res = min(res, *(b + k - 1) - *b);
        b++;
    }

    cout << "The difference between min and max chocolate is: " << res << '\n';
    return 0;
}