#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <string>

int eval(std::string &ps)
{
    std::vector<std::string> postfix;
    std::string token = "";
    for (const char &ele : ps)
    {
        if (ele == ' ')
        {
            postfix.push_back(token);
            token = "";
        }
        else
            token += ele;
    }
    postfix.push_back(token);

    std::stack<std::string> s;
    std::string operators = "+-*/^";
    for (const std::string &ele : postfix)
    {
        if (operators.find(ele) != -1)
        {
            int operant_2 = std::stoi(s.top());
            s.pop();
            int operant_1 = std::stoi(s.top());
            s.pop();
            int res = 0;

            switch (ele[0])
            {
            case '+':
                res = operant_1 + operant_2;
                break;
            case '-':
                res = operant_1 - operant_2;
                break;
            case '*':
                res = operant_1 * operant_2;
                break;
            case '/':
                res = operant_1 / operant_2;
                break;
            case '^':
                res = std::pow(operant_1, operant_2);
                break;
            };

            s.push(std::to_string(res));
        }
        else
            s.push(ele);
    }

    return std::stoi(s.top());
}

int main()
{
    std::string postfix;
    std::cout << "Enter the postfix expresion (with spaces): ";
    getline(std::cin, postfix);
    std::cout << "The evaluated result is: " << eval(postfix) << '\n';
    return 0;
}