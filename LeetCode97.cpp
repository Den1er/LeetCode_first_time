46. Permutations
//自己写的，记住，传参的时候一定要想清楚 --count 和 count - 1 区别很大
//效率很低！！别人可以不使用额外空间
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        if(nums.size() == 0)
        {
            return result;
        }
        vector<int> tmp;
        vector<bool> map(nums.size(), 0);
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


//贴上一个很高手的解法
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        
        permuteRecursive(num, 0, result);
        return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
        if (begin >= num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }
        
        for (int i = begin; i < num.size(); i++) {
            swap(num[begin], num[i]);
            permuteRecursive(num, begin + 1, result);
            // reset
            swap(num[begin], num[i]);
        }
    }
};