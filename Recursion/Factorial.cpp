#include <iostream>

using namespace std;

long long fact(int n)
{
    if (n <= 1)
    {
        cout << "1 = ";
        return 1;
    }

    cout << n << " x ";
    return n * fact(n - 1);
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << num << "! = " << fact(num) << '\n';
    return 0;
}