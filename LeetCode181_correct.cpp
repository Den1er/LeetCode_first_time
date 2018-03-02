152. Maximum Product Subarray
//只能说这道题我想了好久好久，状态都没有找对，忽略考虑了一种情况，负负得正也可以拿到最大值
//实在是太naive了
//还是要多做DP题，想不到状态可不是什么好事
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        int res = nums[0];
        int max_local = nums[0];
        int min_local = nums[0];

        int n = nums.size();
        for(int i = 1; i < n; ++i)
        {
            int tmp = max_local;
            max_local = max(max(max_local * nums[i], nums[i]), min_local * nums[i]);
            min_local = min(min(min_local* nums[i], nums[i]), tmp * nums[i]);
            res = max(res, max_local);
        }
        return res;
    }

};
