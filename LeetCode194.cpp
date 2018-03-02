279. Perfect Squares
//状态方程，dp[j * j + i] = min(dp[j * j + 1], dp[i] + 1)
class Solution {
public:
    int numSquares(int n) {
        if(n <= 3) return n;
        vector<int> dp(n + 1, 100000);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 0; i * i <= n; ++i) dp[i * i] = 1;

        for(int i = 4; i < n + 1; ++i)
        {
            
            for(int j = 0; j * j + i <= n; ++j)
            {
                dp[j * j + i] = min(dp[j * j + i], dp[i] + 1);
            }
        }
        return dp[n];
    }
};
