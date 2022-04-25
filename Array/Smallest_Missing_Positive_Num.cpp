/*
? You are given an array arr[] of N integers including 0.
? The task is to find the smallest positive number missing from the array.
*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void display_container(T start, T end, string seperator = ",")
{
    if (start == end)
    {
        cout << "AN Empty container....\n";
        return;
    }
    end--;
    while (start != end)
    {
        cout << *start << " " << seperator << " ";
        start++;
    }
    cout << *start << '\n';
}

template <typename T>
T segregate_(T b, T e)
{
    T f_positive = e;
    while (b < e)
    {
        if (*b > 0 && f_positive == e)
        {
            f_positive = b;
        }
        else if (*b <= 0 && f_positive != e)
        {
            *f_positive += *b;
            *b = *f_positive - *b;
            *f_positive -= *b;

            f_positive++;
        }
        b++;
    }
    return f_positive;
}

template <typename T>
void freq(T b, T e)
{
    T begin = b;
    while (b < e)
    {
        if (*b <= 0)
        {
            b++;
            continue;
        }

        T loc = begin + (*b) - 1;
        if (loc >= e)
        {
            b++;
        }
        else if (*loc > 0)
        {
            *b = *loc;
            *loc = -1;
        }
        else
        {
            *loc -= 1;
            b++;
        }
    }
}

template <typename T>
int smallest_missing(T b, T e)
{
    int min = distance(b, e) + 1; // if all elements are present then return max +1
    T begin = b;
    while (b < e)
    {
        if (*b > 0)
            return distance(begin, b) + 1;
        b++;
    }
    return min;
}

int main()
{
    // int arr[] = {0, -10, 1, 3, -20};
    int arr[] = {1, 2, 3, 4, 10, 22, 5};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int>::iterator b = v.begin(), e = v.end(), f_positive = segregate_(b, e);

    if (f_positive == e)
    {
        // no element more than 0
        cout << "The first missing positive int is: 1\n";
    }

    freq(f_positive, e);

    cout << "The first missing positive int is: " << smallest_missing(f_positive, e) << '\n';
    return 0;
}
