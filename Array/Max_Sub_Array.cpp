#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // int arr[] = {-5, 1, -2, 3, -1, 2, -2};
    int arr[] = {-3, 8, -2, 4, -5, 6};
    // int arr[] = {-5};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    int max_sub_sum = *b, max_sum = *b;

    e--;
    b++;
    while (b <= e)
    {
        max_sub_sum = max(max_sub_sum + *b, *b);
        max_sum = max(max_sum, max_sub_sum);
        b++;
    }

    cout << "The maximum sum is: " << max_sum << '\n';
    return 0;
}
