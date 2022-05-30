#include <iostream>
#include <vector>
#include <deque>

void window_max(std::vector<int> &v, const int k)
{
    std::deque<int> dq;
    const int v_size = v.size();

    for (int i = 0; i < v_size; i++)
    {
        while (!dq.empty() && v[dq.back()] < v[i])
            dq.pop_back();
        dq.push_back(i);

        if (i >= k - 1)
        {
            std::cout << v[dq.front()] << ' ';
            if (dq.front() == i - k + 1)
                dq.pop_front();
        }
    }
}

int main()
{
    using std::cout;

    // int arr[] = {20, 40, 30, 10, 60};
    int arr[] = {10, 8, 5, 12, 15, 7, 6};
    const int k = 3;
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "Input Array: ";
    for (const int &ele : v)
    {
        cout << ele << ' ';
    }
    cout << '\n';

    cout << "The max of windows of size " << k << ": ";
    window_max(v, k);
    cout << '\n';
    return 0;
}