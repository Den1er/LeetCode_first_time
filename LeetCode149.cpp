53. Maximum Subarray
//DP，一开始没有看出来这是一道动态规划的题，实际上还是可以设置状态值为包含当前节点并且以当前节点作为最后一个元素的子数组的最大值
//本题与robber house很像，看完之后，我打算去修改一下robber house的解法了
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        int globalmax = nums[0];
        int localmax = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            localmax += nums[i];
            if(localmax > globalmax)
                globalmax = localmax;
            if(localmax < 0)
                localmax = 0;
        }
        return globalmax;
    }
};