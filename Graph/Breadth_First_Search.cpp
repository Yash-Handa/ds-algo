#include <iostream>
#include <vector>
#include <queue>

void bfs(std::vector<std::vector<int>> &g, const int s)
{
    std::vector<bool> visited(g.size(), false);
    std::queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        std::cout << curr << ' ';

        for (const int &ele : g[curr])
            if (!visited[ele])
            {
                visited[ele] = true;
                q.push(ele);
            }
    }
}

int main()
{
    std::vector<std::vector<int>> g = {{1, 2},
                                       {0, 2, 3},
                                       {0, 1, 3, 4},
                                       {1, 2, 4},
                                       {2, 3}};
    const int s = 0;

    std::cout << "The Breath-First Search from " << s << " is: ";
    bfs(g, s);
    std::cout << '\n';
}