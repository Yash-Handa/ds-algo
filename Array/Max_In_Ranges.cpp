#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int l_bound[] = {1, 2, 3};
    int r_bound[] = {3, 5, 7};
    vector<int> v(10), prefix_sum(10);

    for (int i = 0; i < 3; i++)
        v[l_bound[i]] = 1;

    for (int i = 0; i < 3; i++)
        v[r_bound[i] + 1] = -1;

    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        prefix_sum[i] = sum;
    }

    // find the max in prefix_sum
    int max = 0, index;
    for (int i = 0; i < prefix_sum.size(); i++)
    {
        if (prefix_sum[i] > max)
        {
            index = i;
            max = prefix_sum[i];
        }
    }

    cout << "The element with max occurrence is: " << index << '\n';
    return 0;
}