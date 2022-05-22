#include <iostream>
#include <stack>

using std::cout, std::cin, std::string, std::stack;

bool matching(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

bool is_balanced(string &str)
{
    stack<char> s;

    for (char &ele : str)
    {
        if (ele == '{' || ele == '[' || ele == '(')
            s.push(ele);
        else if (ele == '}' || ele == ']' || ele == ')')
        {
            if (s.empty())
                return false;
            else if (!matching(s.top(), ele))
                return false;
            else
                s.pop();
        }
    }

    return (s.empty());
}

int main()
{
    string str;
    cout << "Enter the parenthesis list: ";
    getline(cin, str);
    cout << "The parenthesis \"" << str << "\" are " << (is_balanced(str) ? "" : "not ") << "balanced\n";
    return 0;
}
