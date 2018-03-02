221. Maximal Square
//这道题是看网上的思路做出来的
//暴力解法，遍历x,y时间复杂度n*n,遍历边长,n^3,扫描边内的区域，累计n^5
//如果计算区域大小不需要n^2，时间复杂度就变为n^3
//DP思路就是通过公式计算(0,0)到(i - 1,j - 1)之间1的总和dp[i][j]，再通过这个结果计算区域内的面积，check是否是矩形
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)  return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        //dp[i][j]:sum from (0, 0) to (i - 1, j - 1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1] - '0';

        int res = 0;
        
        for(int x = 0; x < m; ++x)
            for(int y = 0; y < n; ++y)
            {
                int size = min(m - x , n - y );
                for(int k = size; k > 0; --k)
                {
                    
                    int tmp = dp[x + k][y + k] - dp[x][y + k] - dp[x + k][y] + dp[x][y];
                    if(tmp == k * k)
                    {
                        res = max(res, tmp);
                    }
                    
                }
            }
            
        return res;
    }

};
