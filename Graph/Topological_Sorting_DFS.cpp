#include <iostream>
#include <vector>
#include <stack>

using std::vector;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, std::stack<int> &s, int i)
{
    visited[i] = true;
    for (int ele : graph[i])
        if (!visited[ele])
            dfs(graph, visited, s, ele);

    s.push(i);
}

void topological_sort(vector<vector<int>> &graph)
{
    const int sz = graph.size();
    vector<bool> visited(sz, false);
    std::stack<int> s;

    for (int i = 0; i < sz; i++)
        if (!visited[i])
            dfs(graph, visited, s, i);

    // print elements from stack
    std::cout << "The Topological Sort (using DFS) is: ";
    while (!s.empty())
    {
        std::cout << s.top() << ' ';
        s.pop();
    }
    std::cout << '\n';
}

int main()
{
    vector<vector<int>> graph = {{2, 3}, {3, 4}, {3}, {}, {}};
    topological_sort(graph);
}