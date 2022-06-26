#include <iostream>
#include <vector>

void dfs_rec(std::vector<std::vector<int>> &graph, std::vector<bool> &visited, const int s)
{
    visited[s] = true;
    std::cout << s << ' ';
    for (const int &ele : graph[s])
        if (!visited[ele])
            dfs_rec(graph, visited, ele);
}

void dfs(std::vector<std::vector<int>> &graph)
{
    const int sz = graph.size();
    std::vector<bool> visited(sz, false);
    for (int i = 0; i < sz; i++)
        if (!visited[i])
            dfs_rec(graph, visited, i);
}

int main()
{
    std::vector<std::vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 3}, {1, 2, 4}, {1, 3}};
    std::cout << "The Depth-First Search is: ";
    dfs(graph);
    std::cout << '\n';
}