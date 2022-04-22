#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {5, 0, 1, 4, 3, -3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    int sum = 0, l_sum = 0;
    bool is_eq = false;

    e--;
    while (b <= e)
    {
        sum += *b;
        b++;
    }

    b = v.begin();
    while (b <= e)
    {
        if (l_sum == sum - *b)
        {
            is_eq = true;
            break;
        }
        l_sum += *b;
        sum -= *b;
        b++;
    }

    string ans = is_eq ? "True" : "False";
    cout << "Array has an equilibrium point: " << ans << '\n';
    return 0;
}