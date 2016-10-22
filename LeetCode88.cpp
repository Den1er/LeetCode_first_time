200. Number of Islands
DFS+BFS，题目思路是参考网上的，第一次碰到确实想不到
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if(grid.size()==0||grid[0].size()==0)
            return result;
        for(int i = 0; i<grid.size(); ++i)
        {
            for(int j = 0; j<grid[i].size(); ++j)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid, i, j);
                    ++result;
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<char>>& grid, int n, int m)
    {
        grid[n][m] = '0';
        if(n>0&&grid[n-1][m]=='1')
        {
            dfs(grid, n-1, m);
        }
        if((n<grid.size()-1)&&grid[n+1][m]=='1')
        {
            dfs(grid, n+1, m);
        }
        if((m<grid[0].size()-1)&&grid[n][m+1]=='1')
        {
            dfs(grid, n, m+1);
        }
        if((m>0)&&grid[n][m-1]=='1')
        {
            dfs(grid, n, m-1);
        }
    }
};