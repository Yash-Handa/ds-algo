#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool has_pair(T b, T e, int sum)
{
    if (b == e)
        return false;

    e--;
    while (b < e)
    {
        if (*b + *e == sum)
            return true;
        else if (*b + *e > sum)
            e--;
        else
            b++;
    }
    return false;
}

template <typename T>
void py_triplet(T b, T e)
{
    vector<int> v_sq;
    while (b < e)
    {
        v_sq.push_back(*b * *b);
        b++;
    }
    b = v_sq.begin();
    e = v_sq.end();

    sort(b, e);

    e--;
    while (b < e)
    {
        if (has_pair(b, e, *e) == true)
        {
            cout << "There exists a Pythagorean Triplet\n";
            return;
        }
        e--;
    }
    cout << "There DOES NOT exists a Pythagorean Triplet\n";
    return;
}

int main()
{
    int arr[] = {3, 1, 4, 6, 5};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end();

    py_triplet(b, e);
    return 0;
}