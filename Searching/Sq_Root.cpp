#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num;
    cout << "Enter the number to calculate sqrt: ";
    cin >> num;

    int b = 1, e = num, ans;
    while (b <= e)
    {
        int mid = floor((b + e) / 2);
        int mid_sq = mid * mid;

        if (mid_sq == num)
        {
            cout << "The square root is: " << mid << '\n';
            return 0;
        }
        else if (mid_sq > num)
            e = mid - 1;
        else
        {
            b = mid + 1;
            ans = mid;
        }
    }

    cout << "The square root is: " << ans << '\n';
    return 0;
}