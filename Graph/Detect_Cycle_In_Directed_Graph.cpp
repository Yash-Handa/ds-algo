#include <iostream>
#include <vector>

using std::vector;

bool has_cycle_rec(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &rec_stack, int s)
{
    visited[s] = true;
    rec_stack[s] = true;
    for (int ele : graph[s])
    {
        if (!visited[ele])
        {
            if (has_cycle_rec(graph, visited, rec_stack, ele))
                return true;
        }
        else if (rec_stack[ele])
            return true;
    }

    rec_stack[s] = false;
    return false;
}

bool has_cycle(vector<vector<int>> &graph)
{
    const int sz = graph.size();
    vector<bool> visited(sz, false);
    vector<bool> rec_stack(sz, false);

    for (int i = 0; i < sz; i++)
        if (!visited[i])
            if (has_cycle_rec(graph, visited, rec_stack, i))
                return true;
    return false;
}

int main()
{
    vector<vector<int>> graph = {{1}, {}, {1, 3}, {4}, {5}, {3}};
    // vector<vector<int>> graph = {{1}, {}, {1}};
    std::cout << "The Graph " << (has_cycle(graph) ? "has" : "does not have") << " a cycle\n";
}