198. House Robber
//DP，状态值表示到当前房屋时最大的金钱数，一直算到最后一个也不一定是最大的，需要遍历一遍所有的结果，返回最大值
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        if(nums.size() == 1)    return nums[0];
        int premium[nums.size()];
        premium[0] = nums[0];
        premium[1] = nums[1];
        for(int i = 2; i < nums.size(); ++i)
        {
            premium[i] = 0;
            for(int j = 0; j < i - 1; ++j)
            {
                if(premium[j] + nums[i] > premium[i])
                    premium[i] = premium[j] + nums[i];
            }
        }
        for(int i = 1; i < nums.size(); ++i)
        {
            if(premium[i] > premium[0])
                premium[0] = premium[i];
        }
        return premium[0];
        
    }
};

//自己做了修改之后的解法，基本上属于每次计算出来一个最大值立马与全局最大值进行比较
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0], nums[1]);
        int premium[nums.size()];
        premium[0] = nums[0];
        premium[1] = nums[1];
        int globalmax = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i)
        {
            premium[i] = 0;
            for(int j = 0; j < i - 1; ++j)
            {
                if(premium[j] + nums[i] > premium[i])
                    premium[i] = premium[j] + nums[i];
            }
            if(premium[i] > globalmax)
                globalmax = premium[i];
        }
        
        return globalmax;
        
    }
};