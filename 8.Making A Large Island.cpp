// Day 8: 16/10/23 21:03
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    int dfs(vector<vector<int>> &grid, int x, int y, int color)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1)
            return 0;

        grid[x][y] = color;
        int size = 1;

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            size += dfs(grid, newX, newY, color);
        }

        return size;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int maxIslandSize = 0;
        int color = 2;

        unordered_map<int, int> colorSizeMap;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int islandSize = dfs(grid, i, j, color);
                    maxIslandSize = max(maxIslandSize, islandSize);
                    colorSizeMap[color] = islandSize;
                    color++;
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    unordered_set<int> neighborColors;
                    int newSize = 1;

                    for (int k = 0; k < 4; ++k)
                    {
                        int newX = i + dx[k];
                        int newY = j + dy[k];

                        if (newX >= 0 && newX < n && newY >= 0 && newY < n)
                        {
                            int neighborColor = grid[newX][newY];
                            if (neighborColor != 0)
                                neighborColors.insert(neighborColor);
                        }
                    }

                    for (int neighborColor : neighborColors)
                    {
                        newSize += colorSizeMap[neighborColor];
                    }

                    maxIslandSize = max(maxIslandSize, newSize);
                }
            }
        }

        return maxIslandSize;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        Solution ob;
        cout << ob.largestIsland(grid) << endl;
    }
    return 0;
}
