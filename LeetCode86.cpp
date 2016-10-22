1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> dup = nums;
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size()-1;
        while(nums[left]+nums[right]!=target)
        {
            if(nums[left]+nums[right]<target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        vector<int> result;
        int index_l,index_r;
        for(int i = 0; i<dup.size(); ++i)
        {
            if(dup[i]==nums[left])
            {
                index_l = i;
                break;
            }
        }
        for(int i = dup.size()-1; i>=0; --i)
        {
            if(dup[i]==nums[right])
            {
                index_r = i;
                break;
            }
        }
        result.push_back(index_l);
        result.push_back(index_r);
        return result;
    }
};