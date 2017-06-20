40. Combination Sum II
//自己写的
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        dfs(target, tmp, result, candidates, 0);
        return result;
    }
    void dfs(int target, vector<int>& tmp, vector<vector<int>>& result,vector<int>& candidates, int begin)
    {
        if(target == 0)
        {
            vector<vector<int>>::iterator it;
            it = find(result.begin(), result.end(), tmp);
            if(it == result.end())
            {
                result.push_back(tmp);
                //tmp.pop_back();
            }
            return;
        }
        int length = candidates.size();
        for(int i = begin; i < length && candidates[i] <= target; ++i )
        {
            tmp.push_back(candidates[i]);
            dfs(target - candidates[i], tmp, result, candidates, i + 1);
            tmp.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target)
    {
        vector<vector<int>> res;
        sort(num.begin(),num.end());
        vector<int> local;
        findCombination(res, 0, target, local, num);
        return res;
    }
    void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num)
    {
        if(target==0)
        {
            res.push_back(local);
            return;
        }
        else
        {
            for(int i = order;i<num.size();i++) // iterative component
            {
                if(num[i]>target) return;
                if(i&&num[i]==num[i-1]&&i>order) continue; // check duplicate combination  很精髓，每一层只选择一种元素，很重要
            
                local.push_back(num[i]),
                findCombination(res,i+1,target-num[i],local,num); // recursive componenet
                local.pop_back();
            }
        }
    }
};