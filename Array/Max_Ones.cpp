#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // int arr[] = {0, 0, 0, 0, 0};
    // int arr[] = {1, 1, 1, 1, 1, 1};
    int arr[] = {1, 0, 1, 1, 1, 1, 0, 1, 1};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    int max_sum = 0, sum = 0;

    e--;
    while (b <= e)
    {
        if (*b == 0)
            sum = 0;
        else
        {
            sum++;
            if (sum > max_sum)
                max_sum = sum;
        }
        b++;
    }

    cout << "The maximum number of consecutive 1s is: " << max_sum << '\n';
    return 0;
}
