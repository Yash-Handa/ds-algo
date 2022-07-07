// Kosaraju Algorithm is used to find strongly connected components of a directed graph
#include <iostream>
#include <vector>
#include <stack>

using std::vector;

vector<vector<int>> transpose(vector<vector<int>> &graph)
{
    const int Vert = graph.size();
    vector<vector<int>> t_graph(Vert, vector<int>());

    for (int r = 0; r < Vert; r++)
        for (int ele : graph[r])
            t_graph[ele].push_back(r);

    return t_graph;
}

void dfs_mod(vector<vector<int>> &graph, vector<bool> &visited, std::stack<int> &s, int i)
{
    visited[i] = true;
    for (int ele : graph[i])
        if (!visited[ele])
            dfs_mod(graph, visited, s, ele);

    s.push(i);
}

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int s)
{
    visited[s] = true;
    std::cout << s << ' ';
    for (int ele : graph[s])
        if (!visited[ele])
            dfs(graph, visited, ele);
}

void kosaraju(vector<vector<int>> &graph)
{
    const int Vert = graph.size();
    vector<bool> visited(Vert, false);
    std::stack<int> s;

    // fill the stack
    for (int i = 0; i < Vert; i++)
        if (!visited[i])
            dfs_mod(graph, visited, s, i);

    // transpose the graph
    vector<vector<int>> t_graph = transpose(graph);

    // do dfs or bfs search on the transpose graph in order of elements in the stack
    visited = vector<bool>(Vert, false);
    while (!s.empty())
    {
        if (!visited[s.top()])
        {
            dfs(t_graph, visited, s.top());
            std::cout << '\n';
        }
        s.pop();
    }
}

int main()
{
    vector<vector<int>> graph = {{1}, {2}, {3}, {0, 4}, {5}, {4}};
    // vector<vector<int>> graph = {{1}, {2, 3}, {}, {0}};

    std::cout << "The strongly connected vertices in the directed graph are (using Kosaraju Algorithm):\n";
    kosaraju(graph);
}