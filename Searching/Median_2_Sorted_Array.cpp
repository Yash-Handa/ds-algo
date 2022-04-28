#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double median(vector<int> &v1, vector<int> &v2)
{
    vector<int>::iterator b = v1.begin(), e = v1.end();
    int s1 = v1.size(), s2 = v2.size();

    // e--; // go beyond the last element because if smaller array has all smaller values then mid needs to point beyond the last element.
    while (b <= e)
    {
        vector<int>::iterator mid1 = b + floor(distance(b, e) / 2);
        vector<int>::iterator mid2 = v2.begin() + floor((s1 + s2 + 1) / 2) - distance(v1.begin(), mid1);

        // cout << "mid1 value: " << *mid1 << "\tmid2 value: " << *mid2 << '\n';

        int r_min1 = mid1 == v1.end() ? INT32_MAX : *mid1;
        int l_max1 = mid1 == v1.begin() ? INT32_MIN : *(mid1 - 1);
        int r_min2 = mid2 == v2.end() ? INT32_MAX : *mid2;
        int l_max2 = mid2 == v2.begin() ? INT32_MIN : *(mid2 - 1);

        // cout << "r_min1: " << r_min1 << "\tl_max1: " << l_max1 << "\tr_min2: " << r_min2 << "\tl_max2: " << l_max2 << "\n\n";

        if (r_min1 >= l_max2 && r_min2 >= l_max1)
        {
            // found the exact points where median is present
            if ((s1 + s2) % 2 == 0)
                return (double)(max(l_max1, l_max2) + min(r_min1, r_min2)) / 2;
            else
                return (double)max(l_max1, l_max2);
        }
        else if (r_min1 < l_max2)
            b = mid1 + 1;
        else
            e = mid1 - 1;
    }
    return double(0);
}

int main()
{
    // int a1[] = {30, 40, 50, 60}, a2[] = {5, 6, 7, 8, 9};
    // int a1[] = {9, 30, 40, 50, 60}, a2[] = {5, 6, 7, 8};
    int a1[] = {10, 20, 30}, a2[] = {5, 15, 25, 35, 45};

    int s1 = sizeof(a1) / sizeof(a1[0]);
    int s2 = sizeof(a2) / sizeof(a2[0]);

    // v1 is the smaller vector
    vector<int> v1, v2;
    if (s1 <= s2)
    {
        v1 = vector<int>(a1, a1 + s1);
        v2 = vector<int>(a2, a2 + s2);
    }
    else
    {
        v1 = vector<int>(a2, a2 + s2);
        v2 = vector<int>(a1, a1 + s1);
    }

    cout << "The median of the given arrays is: " << median(v1, v2) << '\n';
    return 0;
}