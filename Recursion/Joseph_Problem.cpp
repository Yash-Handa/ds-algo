#include <iostream>

using namespace std;

int jp(int n, int k = 3)
{
    if (n == 1)
        return 1;

    return (jp(n - 1, k) + k - 1) % n + 1;
}

int main()
{
    int n;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "The servivor is: " << jp(n, 3) << '\n';
    return 0;
}