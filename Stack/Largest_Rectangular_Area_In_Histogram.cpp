#include <iostream>
#include <vector>
#include <stack>

int largest_area(std::vector<int> &v)
{
    std::stack<int> s;
    int v_size = v.size(), res = 0;
    for (int i = 0; i < v_size; i++)
    {
        // for elements which have next smaller elements
        while (!s.empty() && v[s.top()] > v[i])
        {
            int length = v[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            res = std::max(res, length * width);
        }
        s.push(i);
    }

    // for elements which do not have next smaller element
    while (!s.empty())
    {
        int length = v[s.top()];
        s.pop();
        int width = s.empty() ? v_size : v_size - s.top() - 1;
        res = std::max(res, length * width);
    }

    return res;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    // int arr[] = {7, 7, 7};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::cout << "The largest possible Rectangular Area in the histogram is: " << largest_area(v) << '\n';
    return 0;
}