#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int max_people(T b_1, T e_1, T b_2, T e_2)
{
    sort(b_1, e_1);
    sort(b_2, e_2);
    int result = 0, count = 0;
    while (b_1 < e_1 && b_2 < e_2)
    {
        if (*b_1 <= *b_2)
        {
            count++;
            b_1++;
        }
        else
        {
            count--;
            b_2++;
        }
        result = max(result, count);
    }
    return result;
}

int main()
{
    int arr_1[] = {900, 600, 700};
    int arr_2[] = {1000, 800, 730};
    vector<int> v_1(arr_1, arr_1 + sizeof(arr_1) / sizeof(arr_1[0]));
    vector<int> v_2(arr_2, arr_2 + sizeof(arr_2) / sizeof(arr_2[0]));
    vector<int>::iterator b_1 = v_1.begin(), e_1 = v_1.end(), b_2 = v_2.begin(), e_2 = v_2.end();

    cout << "The maximum people you can meet is: " << max_people(b_1, e_1, b_2, e_2) << '\n';
    return 0;
}
