#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {5, 10, 20, 6, 3, 8};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    int curr_len = 1, max_len = 1;

    e--;
    b++; // strart the loop at index 1 (second element)
    while (b <= e)
    {
        if (*b % 2 == *(b - 1) % 2)
            curr_len = 1;
        else
        {
            curr_len++;
            max_len = max(max_len, curr_len);
        }
        b++;
    }

    cout << "The maximum length of Even Odd sub Array is: " << max_len << '\n';
    return 0;
}
