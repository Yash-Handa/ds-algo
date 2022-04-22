#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // int arr[] = {5, 5, 5, 5, 5, 5, 5};
    // int arr[] = {5, 4, 3, 2, 1};
    int arr[] = {5, 0, 1, 4, 3, 4};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    int profit = 0, l_max, l_min;
    bool in_business = false;

    e--;
    while (b <= e)
    {
        if (b == v.begin())
        {
            if (*b < *(b + 1))
                l_min = *b;
        }
        else if (b == v.end() - 1)
        {
            if (*b > *(b - 1))
            {
                l_max = *b;
                in_business = true;
            }
        }
        else
        {
            if (*b < *(b - 1) && *b < *(b + 1))
                l_min = *b;
            else if (*b > *(b - 1) && *b > *(b + 1))
            {
                l_max = *b;
                in_business = true;
            }
        }

        if (in_business)
        {
            profit += l_max - l_min;
            in_business = false;
        }

        b++;
    }

    cout << "Total Profit is: " << profit << '\n';

    return 0;
}