/*
? Given a string S such that it may contain repeated lowercase alphabets.
? Rearrange the characters in the string such that no two adjacent characters are same.
*/
#include <iostream>
#include <queue>
#include <unordered_map>

class comp
{
public:
    bool operator()(std::pair<char, int> &e1, std::pair<char, int> &e2)
    {
        return (e1.second < e2.second);
    }
};

void rearrange(std::string &s)
{
    std::unordered_map<char, int> mp;
    for (const char ele : s)
        mp[ele]++;

    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, comp>
        pq(mp.begin(), mp.end());

    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();

        std::cout << temp.first;

        if (temp.second > 1)
        {
            temp.second--;
            pq.push(temp);
        }
    }
}

int main()
{
    std::string s = "bbbabaaacd";
    std::cout << "One of the possible arrangement " << s << " is: ";
    rearrange(s);
    std::cout << '\n';
}