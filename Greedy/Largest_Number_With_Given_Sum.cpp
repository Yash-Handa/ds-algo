/*
? Geek lost the password of his super locker. He remembers the number of digits N as well as the sum S of all
? the digits of his password. He know that his password is the largest number of N digits that can be made with given sum S.
? As he is busy doing his homework, help him retrieving his password.
*/
#include <iostream>

int largest(int digit, int sum)
{
    int ans = 0, curr_sum = sum, i = digit, num = 9;
    while (curr_sum > 0 && i > 0)
    {
        while (num > curr_sum)
            num--;

        ans = ans * 10 + num;
        curr_sum -= num;
        i--;
    }

    // got out of the loop because we exhausted all digits
    // hence the given number is not possible
    if (curr_sum != 0)
        return -1;

    // found our number but still digits are left
    // add zeros
    while (i != 0)
    {
        ans *= 10;
        i--;
    }

    return ans;
}

int main()
{
    int digits = 5, sum = 12;
    // int digits = 3, sum = 29;
    std::cout << "Largest possible " << digits << " digit number is " << largest(digits, sum) << " with sum " << sum << '\n';
}