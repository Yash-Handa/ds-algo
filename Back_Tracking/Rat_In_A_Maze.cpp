//? Rat is at 0,0 and cheese is at N-1, N-1
#include <iostream>
#include <vector>

using std::vector;

bool solve_maze(vector<vector<bool>> &maze, vector<vector<bool>> &ans, int i, int j, int sz)
{
    if (i == sz - 1 && j == sz - 1)
    {
        ans[i][j] = true;
        return true;
    }
    else if (i < sz && j < sz && maze[i][j])
    {
        ans[i][j] = true;
        if (solve_maze(maze, ans, i + 1, j, sz))
            return true;
        if (solve_maze(maze, ans, i, j + 1, sz))
            return true;
        ans[i][j] = false;
    }

    return false;
}

int main()
{
    vector<vector<bool>> maze = {{1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {0, 1, 0, 0},
                                 {1, 1, 1, 1}};

    vector<vector<bool>> ans(maze.size(), vector<bool>(maze.size(), false));
    if (solve_maze(maze, ans, 0, 0, maze.size()))
    {
        std::cout << "The rat can reach the cheese using the path:\n";
        for (auto &row : ans)
        {
            for (bool ele : row)
                std::cout << ele << ' ';
            std::cout << '\n';
        }
    }
    else
        std::cout << "The rat cannot reach the cheese.\n";
}