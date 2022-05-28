/*
? A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people,
? find if there is a celebrity in the party or not.

? A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column
? j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

? Note: Follow 0 based indexing.
*/
#include <iostream>
#include <vector>

int find_celebrity(std::vector<std::vector<bool>> &matrix)
{
    const size_t sz = matrix.size(); // rows and cols has same size.
    size_t i = 0, j = sz - 1;
    while (i < j)
    {
        // i is not a celebrity, i knows j
        if (matrix[i][j])
            i++;
        else // j is not a celebrity, i doesn't know j
            j--;
    }

    const size_t candidate_index = j;

    for (size_t i = 0; i < sz; i++)
    {
        if (i != candidate_index)
            if (!matrix[i][candidate_index] || matrix[candidate_index][i])
                return -1;
    }
    return candidate_index;
}

int main()
{
    bool m[4][4] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};

    std::vector<std::vector<bool>> matrix(0, std::vector<bool>());
    for (const auto &row : m)
    {
        std::vector<bool> r;
        for (const bool &ele : row)
            r.push_back(ele);
        matrix.push_back(r);
    }

    int id = find_celebrity(matrix);
    id == -1 ? std::cout << "No celebrity is present\n"
             : std::cout << "The celebrity is present at position " << id << '\n';
    return 0;
}