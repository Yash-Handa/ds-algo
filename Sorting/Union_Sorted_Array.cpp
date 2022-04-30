#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void union_(T b_1, T e_1, T b_2, T e_2)
{
    T begin_1 = b_1, begin_2 = b_2;
    while (b_1 < e_1 && b_2 < e_2)
    {
        if (b_1 != begin_1 && *b_1 == *(b_1 - 1))
        {
            b_1++;
            continue;
        }

        if (b_2 != begin_2 && *b_2 == *(b_2 - 1))
        {
            b_2++;
            continue;
        }

        if (*b_1 < *b_2)
        {
            cout << *b_1 << " ";
            b_1++;
        }
        else if (*b_1 > *b_2)
        {
            cout << *b_2 << " ";
            b_2++;
        }
        else
        {
            cout << *b_1 << " ";
            b_1++;
            b_2++;
        }
    }

    while (b_1 < e_1)
    {
        if (b_1 == begin_1 || *b_1 != *(b_1 - 1))
            cout << *b_1 << " ";
        b_1++;
    }

    while (b_2 < e_2)
    {
        if (b_2 == begin_2 || *b_2 != *(b_2 - 1))
            cout << *b_2 << " ";
        b_2++;
    }

    cout << '\n';
}

int main()
{
    int arr_1[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int arr_2[] = {5, 10, 10, 15, 30};
    vector<int> v_1(arr_1, arr_1 + sizeof(arr_1) / sizeof(arr_1[0]));
    vector<int> v_2(arr_2, arr_2 + sizeof(arr_2) / sizeof(arr_2[0]));
    vector<int>::iterator b_1 = v_1.begin(), e_1 = v_1.end(), b_2 = v_2.begin(), e_2 = v_2.end();

    union_(b_1, e_1, b_2, e_2);
    return 0;
}
