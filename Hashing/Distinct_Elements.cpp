#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int arr[] = {1, 3, 2, 4, 5, 6, 4, 5, 6, 5, 3, 1};
    unordered_set<int> s(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << "The count of distinct elements is: " << s.size() << '\n';
    return 0;
}