78. Subsets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> path;
        helper(0,nums,path,result);
        return result;
    }
    void helper(int n, vector<int>& nums, vector<int> path, vector<vector<int>>& result)
    {
        if(n==nums.size())
        {
            result.push_back(path);
            return;
        }
        helper(n+1, nums, path, result);
        path.push_back(nums[n]);
        helper(n+1, nums, path, result);
    }
};