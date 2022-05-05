#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int arr[] = {1, 3, 2, 4, 5, 6, 4, 5, 6, 5, 3, 1};
    unordered_map<int, int> m;

    for (int ele : arr)
        m[ele]++;

    for (auto ele : m)
        cout << "Freq of " << ele.first << " is: " << ele.second << '\n';
    return 0;
}