#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
void n_k_occ(T b, T e, int k)
{
    unordered_map<int, int> m;
    T begin = b;
    int size = distance(b, e);

    // extended mooray's voting algo
    while (b < e)
    {
        if (m.find(*b) != m.end())
            m[*b]++;
        else if (m.size() < k - 1)
            m[*b] = 1;
        else
        {
            auto m_b = m.begin();
            while (m_b != m.end())
            {
                (*m_b).second--;
                if ((*m_b).second == 0)
                    m_b = m.erase(m_b);
                else
                    m_b++;
            }
        }
        b++;
    }

    // verify the result
    for (auto ele : m)
    {
        b = begin;
        int count = 0;
        while (b < e)
        {
            if (*b == ele.first)
                count++;
            b++;
        }

        if (count > size / k)
            cout << ele.first << " ";
    }
}

int main()
{
    int arr[] = {30, 10, 20, 20, 20, 10, 40, 30, 30};
    int k = 4;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << "Elements with more than " << v.size() << "/" << k << " occurrences are: ";
    n_k_occ(v.begin(), v.end(), k);
    cout << '\n';
    return 0;
}