#include <iostream>
#include <vector>

using std::vector;

bool has_cycle_rec(vector<vector<int>> &graph, vector<bool> &visited, int s, int p)
{
    visited[s] = true;
    for (int ele : graph[s])
    {
        if (!visited[ele])
        {
            if (has_cycle_rec(graph, visited, ele, s))
                return true;
        }
        else if (ele != p)
            return true;
    }
    return false;
}

bool has_cycle(vector<vector<int>> &graph)
{
    const int sz = graph.size();
    vector<bool> visited(sz, false);

    for (int i = 0; i < sz; i++)
        if (!visited[i])
            if (has_cycle_rec(graph, visited, i, -1))
                return true;
    return false;
}

int main()
{
    vector<vector<int>> graph = {{1}, {2, 3}, {1, 3, 4}, {1, 2}, {2, 5}, {4}};
    std::cout << "The Graph " << (has_cycle(graph) ? "has" : "does not have") << " a cycle\n";
}