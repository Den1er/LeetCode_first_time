300. Longest Increasing Subsequence
//注意每次初始化的值很值得注意，不要一味地初始化为0，要考虑到真实的含义
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int dp[nums.size()];    //状态代表以nums[i]为最后一个元素的序列的最长序列
        dp[0] = 1;
        int globalmax = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            dp[i] = 1;
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j])
                {
                    if(dp[i] < dp[j] + 1)
                        dp[i] = dp[j] + 1;
                }
            }
            globalmax = dp[i] > globalmax ? dp[i] : globalmax;
        }
        
        return globalmax;
        
    }
};