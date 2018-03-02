695. Max Area of Island
//竟然忘记了深度优先搜索，这类题型很常见，解法一定要注意，这个解法算是模板
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())   return 0;
        maxArea = 0;
        tmp = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == 1)
                {
                    dfs(grid, i, j);
                    maxArea = max(tmp, maxArea);
                    tmp = 0;
                }

        }
        return maxArea;
    }
private:
    int maxArea;
    int tmp;
    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || j <  0 || i >=  grid.size() || j >= grid[0].size() || grid[i][j] == 0)  return;
        ++tmp;
        grid[i][j] = 0;
        for(int k = 0; k < 4; ++k)
        {
            dfs(grid, i + vertical[k], j + horizon[k]);
        }
    }
    int vertical[4] = {1, -1, 0, 0};
    int horizon[4] = {0, 0, -1, 1};
};
