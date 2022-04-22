#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {5, 0, 1, 4, 3, 4};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();
    int l_max = -1, r_max = -1, vol = 0;

    e--;
    while (b <= e)
    {
        if (*b < *e)
        {
            if (*b > l_max)
                l_max = *b;

            vol += l_max - *b;
            b++;
        }
        else
        {
            if (*e > r_max)
                r_max = *e;

            vol += r_max - *e;
            e--;
        }
    }

    cout << "The total volume is: " << vol << '\n';
    return 0;
}
