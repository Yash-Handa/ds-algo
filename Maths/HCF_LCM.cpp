#include <iostream>

using namespace std;

int HCF(int a, int b)
{
    return b == 0 ? a : (b, a % b);
}

int main()
{
    int a, b;
    cout << "enter 2 numbers for HCF and LCM:\n";
    cin >> a;
    cin >> b;
    int h = HCF(a, b);
    cout << "HCF: " << h << '\n';
    cout << "LCM: " << a * b / h << '\n';
    return 0;
}