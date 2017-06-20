473. Matchsticks to Square
//这道题很重要，处理返回值为bool的递归的经典例题       //正方形四边相等
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.empty() || nums.size() < 4)        return false;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
        }
        if(sum % 4 != 0)
        {
            return false;
        }
        int array[4] = {0,0,0,0};
        return helper(nums, array, 0, sum / 4);
        
    }
    bool helper(vector<int>& nums, int* array, int pos, int target)
    {
        if(pos == nums.size())
        {
            if(array[0] == target && array[1] == target && array[2] == target)
            {
                return true;
            }
            return false;
        }
        for(int i = 0; i < 4; ++i)
        {
            if(array[i] + nums[pos] <= target)
            {
                array[i] += nums[pos];
                if(helper(nums, array, pos + 1, target))
                    return true;
                array[i] -= nums[pos];
            }
        }
        return false;
    }
};