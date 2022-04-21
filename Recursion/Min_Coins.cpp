/*
? Given an input amount of change x, write a function to determine the minimum number
? of coins required to make that amount of change.

? Coins: 1, 5, 10, 25
*/

#include <iostream>

using namespace std;

int min_arr(int arr[], int size)
{
    int result = INT32_MAX;
    for (int i = 0; i < size; i++)
        if (arr[i] < result)
            result = arr[i];

    return result;
}

int min_coin(int amt)
{
    if (amt == 0)
        return 0;
    else if (amt < 0)
        return INT32_MAX;

    return 1 + min_arr((int[]){min_coin(amt - 1), min_coin(amt - 5), min_coin(amt - 10), min_coin(amt - 25)}, 4);
}

int main()
{
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;
    cout << "Min. num of change: " << min_coin(amount) << '\n';
    return 0;
}