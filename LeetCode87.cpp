90. Subsets II
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> path;
        vector<vector<int>> result;
        //unordered_map<vector<int>,bool> dup;
        helper(0, nums, path, result);
        return result;
    }
    void helper(int n, vector<int>& nums, vector<int> path, vector<vector<int>>& result/*, unordered_map<vector<int>,bool>& dup*/)
    {
        if(n==nums.size()/*&&dup.find(path)=dup.end()*/)
        {
            for(int i = 0; i<result.size(); ++i)
            {
                if(path==result[i])
                {
                    return;
                }
                
            }
            result.push_back(path);
            return;
        }
        helper(n+1, nums, path, result/*, dup*/);
        path.push_back(nums[n]);
        helper(n+1, nums, path, result/*, dup*/);
    }
};