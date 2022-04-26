// ? This program returns one of the peak.
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int arr[] = {5, 20, 40, 30, 20, 50, 60};
    // int arr[] = {3, 4, 2, 3, 1, 3, 2};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();
    int ans;

    e--;
    while (b <= e)
    {
        vector<int>::iterator mid = b + floor(distance(b, e) / 2);

        if ((mid == v.begin() || *mid > *(mid - 1)) && (mid == v.end() - 1 || *mid > *(mid + 1)))
        {
            ans = *mid;
            break;
        }
        else if (mid > v.begin() && *mid < *(mid - 1))
            e = mid - 1;
        else
            b = mid + 1;
    }

    cout << "The peak is: " << ans << '\n';
    return 0;
}