343. Integer Break
//本题的做法在于找到数字本身或者数字分解出来因素乘积的最大值
class Solution {
public:
    int integerBreak(int n) {
        int dp[n + 1];//代表分成至少两个数或者不分这两种的最大值
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i <= n; ++i)
        {
            dp[i] = 1;
            for(int j = 1; j <= i - 1; ++j)
            {
                int pro1 = max(dp[j], j);
                int pro = max(dp[i - j], i - j);
                if(pro1 * pro > dp[i] )
                    dp[i] = pro1 * pro;
            }
        }
        return dp[n];
    }
};
