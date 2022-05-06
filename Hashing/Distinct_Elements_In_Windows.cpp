#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
void distinct_elements(T b, T e, int window)
{
    unordered_map<int, int> m;
    T begin = b;

    while (b < begin + window)
    {
        m[*b]++;
        b++;
    }

    cout << m.size() << " ";

    b = begin + 1;
    while (b < e - window + 1)
    {
        m[*(b + window - 1)]++;

        if (m[*(b - 1)] == 1)
            m.erase(*(b - 1));
        else
            m[*(b - 1)]--;

        cout << m.size() << " ";
        b++;
    }
}

int main()
{
    int arr[] = {10, 20, 10, 10, 30, 40};
    int window = 4;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "Distinct elements in each window are: ";
    distinct_elements(v.begin(), v.end(), window);
    cout << '\n';
    return 0;
}