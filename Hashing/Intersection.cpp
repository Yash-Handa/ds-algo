#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int arr_1[] = {1, 4, 3, 5, 6, 5}, arr_2[] = {2, 3, 1, 4, 5};
    unordered_set<int> s(arr_1, arr_1 + sizeof(arr_1) / sizeof(arr_1[0]));

    for (int ele : arr_2)
    {
        auto itr = s.find(ele);
        if (itr != s.end())
        {
            cout << *itr << " ";
            s.erase(itr);
        }
    }
    cout << '\n';
    return 0;
}