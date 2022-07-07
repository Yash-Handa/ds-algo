#include <iostream>
#include <vector>

using std::vector;

int mst(vector<vector<int>> &graph)
{
    const int Vert = graph.size();
    vector<bool> mst_set(Vert, false);
    vector<int> curr_weight(Vert, INT32_MAX);
    curr_weight[0] = 0;
    int ans = 0;

    for (int count = 0; count < Vert; count++)
    {
        int u = -1; // index of vertex with min weight and not in mst_set
        for (int i = 0; i < Vert; i++)
            if (!mst_set[i] && (u == -1 || curr_weight[i] < curr_weight[u]))
                u = i;

        mst_set[u] = true;
        ans += curr_weight[u];

        // update curr_weight for all adjacent of u
        for (int v = 0; v < Vert; v++)
            if (graph[u][v] != 0 && !mst_set[v])
                curr_weight[v] = std::min(curr_weight[v], graph[u][v]);
    }

    return ans;
}

int main()
{
    // matrix representation with weights
    vector<vector<int>> graph = {{0, 2, 0, 6, 0},
                                 {2, 0, 3, 8, 5},
                                 {0, 3, 0, 0, 7},
                                 {6, 8, 0, 0, 9},
                                 {0, 5, 7, 9, 0}};

    // vector<vector<int>> graph = {{0, 5, 8, 0},
    //                              {5, 0, 10, 15},
    //                              {8, 10, 0, 20},
    //                              {0, 15, 20, 0}};

    std::cout << "The weight of minimum spanning tree is: " << mst(graph) << '\n';
}