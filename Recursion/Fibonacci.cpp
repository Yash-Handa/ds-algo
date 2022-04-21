/*
? Given an integer n, write a function to compute the nth Fibonacci number.
*/
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T fib_engine(vector<T> &cache, int n)
{
    if (cache[n] == -1)
        cache[n] = fib_engine(cache, n - 1) + fib_engine(cache, n - 2);

    return cache[n];
}

long int fib(int n)
{
    if (n <= 1)
        return n;
    vector<long int> cache(n + 1, -1);
    cache[0] = 0;
    cache[1] = 1;
    return fib_engine(cache, n);
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << n << " fibonacci number is: " << fib(n) << '\n';
    return 0;
}