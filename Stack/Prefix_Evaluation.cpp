#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <string>

int eval(std::string &ps)
{
    std::vector<std::string> prefix;
    std::string token = "";
    for (const char &ele : ps)
    {
        if (ele == ' ')
        {
            prefix.push_back(token);
            token = "";
        }
        else
            token += ele;
    }
    prefix.push_back(token);

    std::stack<std::string> s;
    std::string operators = "+-*/^";
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        std::string ele = prefix[i];
        if (operators.find(ele) != -1)
        {
            int operant_1 = std::stoi(s.top());
            s.pop();
            int operant_2 = std::stoi(s.top());
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
    std::string prefix;
    std::cout << "Enter the prefix expresion (with spaces): ";
    getline(std::cin, prefix);
    std::cout << "The evaluated result is: " << eval(prefix) << '\n';
    return 0;
}