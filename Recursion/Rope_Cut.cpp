#include <iostream>

using namespace std;

int max_3(int a, int b, int c)
{
    return max(c, max(a, b));
}

int max_cuts(int n, int a, int b, int c)
{
    if (n < 0)
        return -1;
    else if (n == 0)
        return 0;

    int res = max_3(max_cuts(n - a, a, b, c), max_cuts(n - b, a, b, c), max_cuts(n - c, a, b, c));
    return res == -1 ? -1 : 1 + res;
}

//! wrong algo... use recursion + tree instead
string possible_cuts(int n, int a, int b, int c)
{
    if (n < 0)
        return "x";
    else if (n == 0)
        return "0\n";

    string valid_a = possible_cuts(n - a, a, b, c);
    string valid_b = possible_cuts(n - b, a, b, c);
    string valid_c = possible_cuts(n - c, a, b, c);
    string one = "x", two = "x", three = "x";

    if (valid_a != "x")
        one = to_string(n) + " -(" + to_string(a) + ")-> " + valid_a;
    if (valid_b != "x")
        two = to_string(n) + " -(" + to_string(b) + ")-> " + valid_b;
    if (valid_c != "x")
        three = to_string(n) + " -(" + to_string(c) + ")-> " + valid_c;

    string ans = "";
    if (one != "x")
        ans += one;
    if (two != "x")
        ans += two;
    if (three != "x")
        ans += three;

    return ans == "" ? "x" : ans;
}

int main()
{
    int n, a, b, c;
    cout << "Enter the rope length: ";
    cin >> n;
    cout << "1st cut: ";
    cin >> a;
    cout << "2nd cut: ";
    cin >> b;
    cout << "3rd cut: ";
    cin >> c;
    cout << "Max number of cuts: " << max_cuts(n, a, b, c) << '\n';
    cout << "Possible Rope cuts:\n";
    cout << possible_cuts(n, a, b, c);
    return 0;
}