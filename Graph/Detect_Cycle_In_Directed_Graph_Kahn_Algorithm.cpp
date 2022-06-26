#include <iostream>
#include <vector>
#include <queue>

using std::vector;

bool has_cycle(vector<vector<int>> &graph)
{
    const int sz = graph.size();

    vector<int> in_degree(sz, 0);
    for (auto adj : graph)
        for (int ele : adj)
            in_degree[ele]++;

    std::queue<int> q;

    for (int i = 0; i < sz; i++)
        if (in_degree[i] == 0)
            q.push(i);

    int count = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        count++;

        for (int ele : graph[curr])
        {
            in_degree[ele]--;
            if (in_degree[ele] == 0)
                q.push(ele);
        }
    }

    return (count != sz);
}

int main()
{
    vector<vector<int>> graph = {{1}, {2, 3}, {1, 3, 4}, {1, 2}, {2, 5}, {4}};
    // vector<vector<int>> graph = {{1}, {2}, {}};
    std::cout << "The Graph " << (has_cycle(graph) ? "has" : "does not have") << " a cycle\n";
}