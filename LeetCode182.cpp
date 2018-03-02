673. Number of Longest Increasing Subsequence
//DP经典题型，这次又想错了，很桑心
//本题的解法算是一个求解最长xx个数的模板，一个数组用于记录长度，一个数组用于记录个数，最后一起核算
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)    return nums.size();
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> num(n, 1);
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[j] < nums[i])
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        num[i] = num[j];
                        dp[i] = dp[j] + 1;
                    }
                    else if(dp[j] + 1 == dp[i])
                    {
                        num[i] = num[i] + num[j];
                    }
                }
            }
        }
        
        int maxlen = 0;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            if(dp[i] > maxlen)
            {
                res = num[i];
                maxlen = dp[i];
            }
            else if(dp[i] == maxlen)
            {
                res += num[i];
            }
        }
        return res;
    }
};
