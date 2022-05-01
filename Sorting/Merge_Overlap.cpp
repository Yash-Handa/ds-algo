#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void display_V_P(T start, T end, string seperator = ",")
{
    if (start == end)
    {
        cout << "AN Empty container....\n";
        return;
    }
    end--;
    while (start != end)
    {
        cout << "[" << (*start).first << ", " << (*start).second << "] " << seperator << " ";
        start++;
    }
    cout << "[" << (*start).first << ", " << (*start).second << "]" << '\n';
}

bool comp(pair<int, int> a, pair<int, int> b)
{
    return (a.first <= b.first);
}

template <typename T>
T merge_interval(T b, T e)
{
    T last = b;
    b++;
    while (b < e)
    {
        if ((*b).first <= (*last).second)
        {
            (*last).second = max((*b).second, (*last).second);
        }
        else
        {
            last++;
            *last = *b;
        }
        b++;
    }

    return last + 1;
}

int main()
{
    // pair<int, int> arr[] = {{3, 10}, {2, 3}, {6, 8}, {1, 7}};
    pair<int, int> arr[] = {{5, 10}, {3, 15}, {18, 30}, {2, 7}};
    vector<pair<int, int>> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<pair<int, int>>::iterator b = v.begin(), e = v.end();

    cout << "Initial Ranges: ";
    display_V_P(b, e);

    sort(b, e, comp);

    vector<pair<int, int>>::iterator end = merge_interval(b, e);

    cout << "Final Ranges:   ";
    display_V_P(b, end);
    return 0;
}