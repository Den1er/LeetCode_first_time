class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        bool helper[n] = {0};
        dp[0] = nums[0];
        helper[0] = 1;

        for(int i = 1; i < n; ++i)
        {
            dp[i] = INT_MIN;
            if(helper[i - 1] == 1)
            {
                //dp[i - 1]  dp[i - 1] * nums[i] nums[i]三者的大小
                int tmp = dp[i - 1] * nums[i];
                dp[i] = max(dp[i - 1], dp[i - 1] * nums[i], nums[i]);
                if(dp[i] == tmp || dp[i] == nums[i])
                    dp[i] = 1;
            }
            else
            {
                //比较dp[i - 1], nums[i]
                dp[i] = max(dp[i - 1], nums[i]);
                if(dp[i] == nums[i])
                    dp[i] = 1;
            }
        }
        return dp[n];
    }
};
