47. Permutations II
//精髓在排序以及去重
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        if(nums.size() == 0)
            return result;
        vector<bool> map(nums.size(), 0);
        sort(nums.begin(), nums.end());
        helper(tmp, nums, result, map, nums.size());
        return result;
        
    }
    void helper(vector<int>& tmp, vector<int> nums, vector<vector<int>>& result, vector<bool> map, int count)
    {
        if(count == 0)
        {
            result.push_back(tmp);
        }
        else
        {
            for(int i = 0; i < nums.size() ; ++i)
            {
                if(map[i] != 1)
                {
                    if(i > 0 && nums[i] == nums[i - 1] && map[i - 1] == 0)  continue; //出重
                    tmp.push_back(nums[i]);
                    map[i] = 1;
                    helper(tmp, nums, result, map, count - 1);
                    map[i] = 0;
                    tmp.pop_back();
                }
                
            }
        }
    }
    
};