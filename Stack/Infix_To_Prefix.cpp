#include <iostream>
#include <stack>
#include <algorithm>

bool lower_presidency(char op, char st)
{
    if (op == '^' && st == '^')
        return true;

    if ((op == '*' || op == '/') && st == '^')
        return true;

    if ((op == '+' || op == '-') && (st != '+' && st != '-' && st != ')'))
        return true;

    return false;
}

std::string prefix(std::string &infix)
{
    std::stack<char> s;
    std::string res, operators = "+-*^/";
    for (int i = infix.size(); i >= 0; i--)
    {
        if (infix[i] == ')')
            s.push(infix[i]);
        else if (infix[i] == '(')
        {
            while (!s.empty() && s.top() != ')')
            {
                res.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else if (operators.find(infix[i]) != -1)
        {
            while (!s.empty() && lower_presidency(infix[i], s.top()))
            {
                res.push_back(s.top());
                s.pop();
            }
            s.push(infix[i]);
        }
        else
            res.push_back(infix[i]);
    }

    while (!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }

    std::reverse(res.begin(), res.end());
    return res;
}

int main()
{
    std::string infix;
    std::cout << "Enter the Infix Expression: ";
    getline(std::cin, infix);

    std::cout << "The Prefix expression is:   " << prefix(infix) << '\n';
    return 0;
}