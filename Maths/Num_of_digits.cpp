#include <iostream>
#include <cmath>

using namespace std;

int digits_1(int n)
{
    int ans = 1;
    while (n > 9)
    {
        n /= 10;
        ans++;
    }
    return ans;
}

int digits_2(int n)
{
    if (n == 0)
        return 1;
    return floor(log10(n) + 1);
}

int main()
{
    int num;
    cout << "Pls enter a number: ";
    cin >> num;
    cout << "Number of digits(1st method): " << digits_1(abs(num)) << '\n';
    cout << "Number of digits(2nd method): " << digits_2(abs(num)) << '\n';
    return 0;
}