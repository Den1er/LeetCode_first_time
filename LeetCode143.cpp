63. Unique Paths II
//与62题稍有不同
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //if(m == 1 || n == 1)    return 1;
        int res[m][n];
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                res[i][j] = 0;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(!obstacleGrid[0][i])
                res[0][i] = 1;
            else
                break;
        }
        for(int i = 0; i < m; ++i)
        {
            if(!obstacleGrid[i][0])
                res[i][0] = 1;
            else
                break;
        }
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(!obstacleGrid[i][j])
                    res[i][j] = res[i - 1][j] + res[i][j - 1];
                else
                    res[i][j] = 0;
            }
        }
        return res[m -1][n - 1];
    }
};
