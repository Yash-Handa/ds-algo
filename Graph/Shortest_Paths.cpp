#include <iostream>
#include <vector>
#include <queue>

std::vector<int> shortest_path(std::vector<std::vector<int>> &graph, const int s)
{
    const int sz = graph.size();
    std::vector<bool> visited(sz, false);
    std::vector<int> dist(sz, INT32_MAX);
    std::queue<int> q;

    visited[s] = true;
    dist[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int ele : graph[curr])
            if (!visited[ele])
            {
                visited[ele] = true;
                dist[ele] = dist[curr] + 1;
                q.push(ele);
            }
    }

    return dist;
}

int main()
{
    std::vector<std::vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2}};
    const int s = 0;

    std::vector<int> dist = shortest_path(graph, s);
    std::cout << "The shortest path of each vertex from " << s << " is:\n";
    for (int sz = dist.size(), i = 0; i < sz; i++)
        std::cout << i << ":\t" << dist[i] << '\n';
}