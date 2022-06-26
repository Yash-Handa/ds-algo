#include <iostream>
#include <vector>
#include <queue>

using std::vector;

void topological_sort(vector<vector<int>> &graph)
{
    const int sz = graph.size();

    // create in_degree vector
    vector<int> in_degree(sz, 0);
    for (auto &adj : graph)
        for (int ele : adj)
            in_degree[ele]++;

    std::queue<int> q;

    // insert every vertex with in-degree as 0 (i.e, no dependencies)
    for (int i = 0; i < sz; i++)
        if (in_degree[i] == 0)
            q.push(i);

    std::cout << "The Topological Sort (using Kahn's Algorithm) is: ";
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        std::cout << curr << ' ';

        for (int ele : graph[curr])
        {
            in_degree[ele]--;
            if (in_degree[ele] == 0)
                q.push(ele);
        }
    }
    std::cout << '\n';
}

int main()
{
    vector<vector<int>> graph = {{2, 3}, {3, 4}, {3}, {}, {}};
    topological_sort(graph);
}