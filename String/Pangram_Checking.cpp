#include <iostream>
#include <unordered_set>

using std::cout, std::string, std::unordered_set;

bool is_pangram(string &str)
{
    unordered_set<char> s;

    for (char ele : str)
    {
        if (ele >= 'a' && ele <= 'z')
            s.insert(ele);
        else if (ele >= 'A' && ele <= 'Z')
            s.insert(tolower(ele));
    }

    return (s.size() == 26);
}

int main()
{
    string str = "Mr. Jock, TV quiz PhD., bags few lynx";
    cout << "The sentence \"" << str << "\" is " << (is_pangram(str) ? "" : "not ") << "a pangram\n";
    return 0;
}