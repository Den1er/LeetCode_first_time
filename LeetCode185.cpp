650. 2 Keys Keyboard
//一维DP，存储的是到该数的最小次数，一开始没有想到除了2以外的除数。。。。
class Solution {
public:
    int minSteps(int n) {
        int dp[1001] = {0};
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        if(n > 2)
            for(int i = 3; i < n + 1; ++i)
                dp[i] = INT_MAX;
        for(int i = 3; i < n + 1; ++i)
        {
            for(int j = 1; j <= i / 2; ++j)
            {
                if(i % j == 0)
                    dp[i] = min(dp[i], dp[j] + i / j);
            }
        }
        return dp[n];
    }
};
