494. Target Sum
//还是要注意边界条件，到最后一个元素的时候，务必要返回。
class Solution {
public:
    int count;
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.empty()) return count;
        helper(nums, S, 0);
        return count;
    }
    void helper(vector<int>& nums, int S, int begin)
    {
        if(begin == nums.size())
        {
            if(S == 0)
            {
                count++;
                return;
            }
            else
                return;
        }
        
        helper(nums, S - nums[begin], begin + 1);
        helper(nums, S + nums[begin], begin + 1);
    }
};