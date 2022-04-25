#include <iostream>
#include <vector>

using namespace std;

void bon(vector<int> &v, int window)
{
    int win_sum = 1;
    vector<int>::iterator b = v.begin(), e = v.end();

    e--;
    b += window;
    while (b <= e)
    {
        *b = win_sum;
        win_sum += *b - *(b - window);
        b++;
    }
}

int main()
{
    int n = 4, m = 10;
    vector<int> cache(m);
    cache[n - 1] = 1;

    bon(cache, n);

    cout << "The " << m << " element of a " << n << "-bonacci series is: " << cache[m - 1] << '\n';

    return 0;
}