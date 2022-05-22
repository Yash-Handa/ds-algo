/*
A c++ program that takes a list of file names from command line and select N number of them.

*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <random>
#include <algorithm>

using std::vector, std::string, std::unordered_set;

int main(int argc, char **argv)
{
    int n = 3;
    if (argc > 1)
        n = std::stoi(string(argv[1]));

    string ignores[] = {
        ".github/workflows/manual.yml",
        ".gitignore",
        "Daily_Practice_Corn_Job.cpp",
        "Daily_Practice",
        "LICENSE",
        "README.md"};

    unordered_set<string> ignore_list(ignores, ignores + sizeof(ignores) / sizeof(ignores[0]));
    vector<string> prog_list;
    string prog_file = "";
    while (getline(std::cin, prog_file))
        if (ignore_list.find(prog_file) == ignore_list.end())
            prog_list.push_back(prog_file);

    n = n > prog_list.size() ? prog_list.size() : n;

    vector<string> selected_progs;
    std::sample(prog_list.begin(),
                prog_list.end(),
                std::back_inserter(selected_progs),
                n,
                std::mt19937{std::random_device{}()});

    for (string ele : selected_progs)
        std::cout << ele << '\n';
    return 0;
}