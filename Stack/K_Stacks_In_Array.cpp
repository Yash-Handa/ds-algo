#include <iostream>
#include <vector>

using std::cout, std::vector;

template <class T>
class K_Stacks
{
private:
    int cap,          // capacity of the arr
        k,            // number of stacks
        free_top;     // index of next free space in arr or -1 (no free space)
    vector<T> arr;    // arr stores the data
    vector<int> next, // stores index of next free space in array or index of prev element in the stack (-1 if last element of the stack)
        tops;         // vector for indics of top of each stack, -1 indicates the stack is empty

public:
    K_Stacks(int cap, int k) : cap(cap), k(k), free_top(0), arr(cap, 0), tops(k, -1), next(cap, 0)
    {
        for (int i = 0; i < cap - 1; i++)
            next[i] = i + 1;
        next[cap - 1] = -1;
    }

    bool is_empty(int k)
    {
        return (tops[k] == -1);
    }

    bool push(T data, int k)
    {
        if (free_top == -1)
            return false;

        int i = free_top;
        free_top = next[free_top];
        next[i] = tops[k];
        tops[k] = i;
        arr[tops[k]] = data;
        return true;
    }

    T pop(int k)
    {
        if (is_empty(k))
            return T(INT32_MAX);

        int top_index = tops[k];
        tops[k] = next[top_index];
        next[top_index] = free_top;
        free_top = top_index;

        return arr[top_index];
    }
};

int main()
{
    K_Stacks<int> ks(5, 2);
    ks.push(5, 0);
    ks.push(10, 1);
    ks.push(20, 0);
    cout << ks.pop(0) << '\n';
    cout << ks.pop(1) << '\n';
    cout << (ks.is_empty(1) ? "True" : "False") << '\n';
    return 0;
}