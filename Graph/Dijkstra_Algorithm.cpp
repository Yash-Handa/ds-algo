#include <iostream>
#include <vector>

using std::vector;

vector<int> dijkstra(vector<vector<int>> &graph, int source)
{
    const int Vert = graph.size();
    vector<bool> finalized(Vert, false);
    vector<int> curr_dist(Vert, INT32_MAX);

    curr_dist[source] = 0;

    for (int count = 0; count < Vert; count++)
    {
        int u = -1;
        for (int i = 0; i < Vert; i++)
            if (!finalized[i] && (u == -1 || curr_dist[i] < curr_dist[u]))
                u = i;

        finalized[u] = true;

        // relax all the adjacent of u
        for (int v = 0; v < Vert; v++)
            if (graph[u][v] != 0 && !finalized[v])
                curr_dist[v] = std::min(curr_dist[v], curr_dist[u] + graph[u][v]);
    }

    return curr_dist;
}

int main()
{
    vector<vector<int>> graph = {{0, 5, 10, 0},
                                 {5, 0, 3, 20},
                                 {10, 3, 0, 2},
                                 {0, 20, 2, 0}};
    int source = 0;

    vector<int> ans = dijkstra(graph, source);
    std::cout << "Distance of each vertex from " << source << " is: \n";
    for (int i = 0; i < ans.size(); i++)
        std::cout << i << ": " << ans[i] << '\n';
}