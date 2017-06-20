62. Unique Paths
//DP，经典题型
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)    return 1;
        int res[m][n];
        for(int i = 0; i < n; ++i)
        {
            res[0][i] = 1;
        }
        for(int i = 0; i < m; ++i)
        {
            res[i][0] = 1;
        }
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
                res[i][j] = res[i - 1][j] + res[i][j - 1];
        }
        return res[m -1][n - 1];
    }
};
