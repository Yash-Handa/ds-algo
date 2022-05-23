/*
Purpose: To get a list of N programs form master branch of Yash-Handa/ds-algo and send them to telegram.

Working: Create msg_1.html, etc files for N selected files,
the content of these msg files are send to telegram using github action
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <random>
#include <algorithm>
#include <fstream>

using std::vector, std::string, std::unordered_set, std::ios, std::cout;

void create_msg_files(vector<string> &selected_progs)
{
    int sz = selected_progs.size();
    for (int i = 0; i < sz; i++)
    {
        string file_name = "msg_" + std::to_string(i + 1) + ".html";
        std::fstream msg_file;
        msg_file.open(file_name, ios::out | ios::trunc);
        if (!msg_file)
        {
            cout << file_name << " couldn't be created\n";
            continue;
        }
        else
        {
            string prog = selected_progs[i];
            string url = "https://github.com/Yash-Handa/ds-algo/blob/master/" + prog;
            std::replace(prog.begin(), prog.end(), '_', ' ');
            std::replace(prog.begin(), prog.end(), '<', ' ');
            std::replace(prog.begin(), prog.end(), '>', ' ');
            std::replace(prog.begin(), prog.end(), '&', ' ');
            auto topic_end = prog.find('/');
            msg_file << "<strong>Topic: <ins>" << prog.substr(0, topic_end) << "</ins></strong>\n";
            msg_file << "<em>Prog Name: " << prog.substr(topic_end + 1, prog.size() - topic_end - 5) << "</em>\n\n";
            msg_file << "<a href=\"" << url << "\">" << selected_progs[i] << "</a>\n";
            msg_file.close();
        }
    }
}

int main(int argc, char **argv)
{
    int n = 3;
    if (argc > 1)
        n = std::stoi(string(argv[1]));

    string ignores[] = {
        ".github/workflows/manual.yml",
        ".github/workflows/corn.yml",
        ".gitignore",
        "Daily_Practice_Corn_Job.cpp",
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

    create_msg_files(selected_progs);
    return 0;
}