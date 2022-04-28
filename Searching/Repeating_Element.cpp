#include <iostream>

using namespace std;

int find_rep(int arr[])
{
    int slow = arr[0] + 1, fast = arr[0] + 1;
    do
    {
        slow = arr[slow] + 1;
        fast = arr[arr[fast] + 1] + 1;
    } while (slow != fast);

    slow = arr[0] + 1;
    while (slow != fast)
    {
        fast = arr[fast] + 1;
        slow = arr[slow] + 1;
    }
    return slow - 1;
}

int main()
{
    int arr[] = {0, 2, 1, 3, 2, 2};

    cout << "The element which is repeating is: " << find_rep(arr) << '\n';
    return 0;
}