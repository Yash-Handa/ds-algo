#include <iostream>

using namespace std;

bool is_prime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void print_primes(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (is_prime(i))
            cout << i << " ";
    }
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    string ans = is_prime(num) ? "True" : "False";
    cout << "Is it prime? " << ans << '\n';
    cout << "Primes till " << num << ": ";
    print_primes(num);
    cout << '\n';
    return 0;
}