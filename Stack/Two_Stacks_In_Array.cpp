#include <iostream>
#include <vector>

using std::cout, std::string, std::vector;

template <class T>
class Two_Stacks
{
private:
    int cap, top_1, top_2;
    vector<T> arr; // use capacity strictly to emulate an array, i.e., no dynamic resizing.

public:
    Two_Stacks(int cap) : cap(cap), top_1(-1), top_2(cap), arr(cap, 0) {}

    int size_1()
    {
        return top_1 + 1;
    }

    int size_2()
    {
        return cap - top_2;
    }

    bool is_empty_1()
    {
        return (top_1 == -1);
    }

    bool is_empty_2()
    {
        return (top_2 == cap);
    }

    bool push_1(T data)
    {
        if (top_1 == top_2 - 1)
            return false;

        top_1++;
        arr[top_1] = data;
        return true;
    }

    bool push_2(T data)
    {
        if (top_1 == top_2 - 1)
            return false;

        top_2--;
        arr[top_2] = data;
        return true;
    }

    T pop_1()
    {
        if (is_empty_1())
            return T(INT32_MAX);

        T data = arr[top_1];
        top_1--;
        return data;
    }

    T pop_2()
    {
        if (is_empty_2())
            return T(INT32_MAX);

        T data = arr[top_2];
        top_2++;
        return data;
    }
};

int main()
{
    Two_Stacks<int> ts(5);
    ts.push_1(5);
    ts.push_2(10);
    ts.push_1(20);
    cout << ts.pop_1() << '\n';
    cout << ts.size_2() << '\n';
    cout << ts.is_empty_1() << '\n';
    return 0;
}