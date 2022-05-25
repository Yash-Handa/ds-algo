#include <iostream>
#include <stack>

using std::cout;

bool lower_presidency(char ele, char st)
{
    if ((ele == '*' || ele == '/') && (st == '*' || st == '/' || st == '^'))
        return true;

    if ((ele == '+' || ele == '-') && st != '(')
        return true;

    return false;
}

void postfix(std::string &infix)
{
    std::stack<char> s;
    const std::string operators = "^/*+-";
    for (const char &ele : infix)
    {
        if (ele == '(')
            s.push(ele);
        else if (ele == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop(); // remove '(' from the stack as well
        }
        else if (operators.find(ele) != -1)
        {
            while (!s.empty() && lower_presidency(ele, s.top()))
            {
                cout << s.top();
                s.pop();
            }
            s.push(ele);
        }
        else
            cout << ele;
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    cout << '\n';
}

int main()
{
    std::string infix;
    cout << "Enter the Infix Expression: ";
    getline(std::cin, infix);

    cout << "The Postfix expression is:  ";
    postfix(infix);
    return 0;
}