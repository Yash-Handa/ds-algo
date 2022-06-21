#include <iostream>
#include <vector>

template <typename T>
class Min_Heap
{
private:
    std::vector<T> v;

    int parent_i(int i)
    {
        return (i - 1) / 2;
    }

    int l_child_i(int i)
    {
        return i * 2 + 1;
    }

    int r_child_i(int i)
    {
        return i * 2 + 2;
    }

    void min_heapify(int i)
    {
        int sz = v.size();
        if (!sz || i >= sz)
            return;

        while (i < sz)
        {
            int min_index = i;
            if (l_child_i(i) < sz && v[l_child_i(i)] < v[min_index])
                min_index = l_child_i(i);
            if (r_child_i(i) < sz && v[r_child_i(i)] < v[min_index])
                min_index = r_child_i(i);

            if (min_index == i)
                break;

            std::swap(v[i], v[min_index]);
            i = min_index;
        }
    }

public:
    Min_Heap() {}

    Min_Heap(std::vector<T> arr) : v(arr.begin(), arr.end())
    {
        int i = (v.size() - 2) / 2; // index of the last internal node (node with children)
        for (; i >= 0; i--)
            min_heapify(i);
    }

    void insert(T ele)
    {
        v.push_back(ele);
        int sz = v.size();

        for (int i = sz - 1; i >= 0 && v[i] < v[parent_i(i)];)
        {
            std::swap(v[i], v[parent_i(i)]);
            i = parent_i(i);
        }
    }

    T get_min() const
    {
        if (v.empty())
            return T(INT32_MAX);
        return v[0];
    }

    T extract_min()
    {
        if (v.empty())
            return T(INT32_MAX);

        T ele = v[0];
        v[0] = v[v.size() - 1];
        v.erase(v.end() - 1);
        min_heapify(0);
        return ele;
    }

    void modify(int i, T ele)
    {
        int sz = v.size();
        if (i >= sz)
            return;

        v[i] = ele;
        int original_i = i;

        // if ele is decreased then try to move upwards
        while (i >= 0 && v[i] < v[parent_i(i)])
        {
            std::swap(v[i], v[parent_i(i)]);
            i = parent_i(i);
        }

        if (i == original_i) // if the ele is increased, try moving downwards
            min_heapify(i);
    }

    void erase(int i)
    {
        if (i >= v.size())
            return;

        modify(i, T(INT32_MIN));
        extract_min();
    }

    int size()
    {
        return v.size();
    }

    bool empty()
    {
        return v.empty();
    }
};

int main()
{
    std::vector<int> v = {34, 56, 23, 67, 11};
    Min_Heap<int> mh(v);

    while (!mh.empty())
        std::cout << mh.extract_min() << ' ';
    std::cout << '\n';

    mh.insert(10);
    mh.insert(55);
    mh.insert(23);
    mh.insert(34);
    mh.erase(2); // remove 23;

    while (!mh.empty())
        std::cout << mh.extract_min() << ' ';
    std::cout << '\n';
}