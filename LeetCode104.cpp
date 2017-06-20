class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<vector<int>> result;
       vector<int> tmp;
       dfs(k, n, 1, tmp, result);
       return result;
    }
    void dfs(int k, int n, int begin, vector<int>& tmp, vector<vector<int>>& result)
    {
        if(k == 0)
        {
            if(n == 0)
            {
                result.push_back(tmp);
            }
            return;
        }
        for(int i = begin; i < 10; ++i)
        {
            tmp.push_back(i);
            dfs(k - 1, n - i, i + 1, tmp, result );
            tmp.pop_back();
        }
    }
};
