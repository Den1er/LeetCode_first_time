//打算用动规做，思路较简单，转移方程:dp[i] = min(dp[j] + dp[i - j], )
//超时了，转移方程找的不对
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
            if(dp[i] == 100000)
            {
                for(int j = i - 1; j * j >= n; --j)
                {
                    dp[i] = min(dp[i], dp[j] + dp[i - j]);
                }
            }
        }
        return dp[n];
    }
};
