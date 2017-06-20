64. Minimum Path Sum
//DP比较简单的题
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res[m][n];
        res[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i)
        {
           res[i][0] = res[i - 1][0] + grid[i][0];
        }

        for(int i = 1; i < n; ++i)
        {
            res[0][i] = res[0][i - 1] + grid[0][i];
        }
        
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                res[i][j] = min(res[i - 1][j] + res[i][j - 1]) + grid[i][j];
            }
        }
        return res[m - 1][n - 1];

    }
};
