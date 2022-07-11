// Bellman Ford algorithm can find shortest paths with negative values as well.
// It is a dynamic solution with time complexity of O(V*E)
#include <iostream>
#include <vector>

using std::vector;

vector<int> bellman_ford(vector<vector<int>> &graph, int source)
{
    const int Vert = graph.size();
    vector<int> dist(Vert, INT32_MAX);
    dist[source] = 0;

    for (int count = 0; count < Vert - 1; count++)
        // relax all the edges
        for (int i = 0; i < Vert; i++)
            for (int j = 0; j < Vert; j++)
                if (graph[i][j] != 0)
                    dist[j] = std::min(dist[j], dist[i] + graph[i][j]);

    // if you want to find presence of a negative sum cycle in the graph then run the the inner loop one more time
    // if any relaxation happens then there exists a negative sum cycle in the graph.

    return dist;
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 4, 0},
                                 {0, 0, -3, 2},
                                 {0, 0, 0, 3},
                                 {0, 0, 0, 0}};
    int source = 0;

    vector<int> ans = bellman_ford(graph, source);
    std::cout << "Distance of each vertex from " << source << " is (using Bellman Ford's Algorithm): \n";
    for (int i = 0; i < ans.size(); i++)
        std::cout << i << ": " << ans[i] << '\n';
}