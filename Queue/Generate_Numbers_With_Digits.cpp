#include <iostream>
#include <vector>
#include <queue>

void numbers(std::vector<int> &v, const int k)
{
    std::queue<int> q;
    for (const int &ele : v)
        q.push(ele);

    int count = 1;
    while (count <= k)
    {
        int data = q.front();
        q.pop();
        for (const int &ele : v)
            q.push(data * 10 + ele);
        std::cout << data << ' ';
        count++;
    }
    std::cout << '\n';
}

int main()
{
    int arr[] = {5, 6};
    int k = 10;
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    std::cout << "The first " << k << " numbers generated from the given digits are: ";
    numbers(v, k);
    return 0;
}