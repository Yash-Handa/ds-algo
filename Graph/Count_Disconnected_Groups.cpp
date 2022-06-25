#include <iostream>
#include <vector>
#include <queue>

void BFS(std::vector<std::vector<int>> &graph, std::vector<bool> &visited, int s)
{
    std::queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int &ele : graph[curr])
            if (!visited[ele])
            {
                visited[ele] = true;
                q.push(ele);
            }
    }
}

int BFS_dis(std::vector<std::vector<int>> &graph)
{
    const int sz = graph.size();
    std::vector<bool> visited(sz, false);
    int ans = 0;
    for (int i = 0; i < sz; i++)
        if (!visited[i])
        {
            ans++;
            BFS(graph, visited, i);
        }

    return ans;
}

int main()
{
    std::vector<std::vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}, {5, 6}, {4, 6}, {4, 5}};
    std::cout << "The number of disconnected groups is: " << BFS_dis(graph) << '\n';
}