class Solution {
public:
        vector<vector<int>> combine(int n, int k) {
                    vector<vector<int>> result;
                    vector<int> path;
                    helper(1, 0, n, k, path, result);
                    return result;
                }
        void helper(int cur, int count, int n, int k, vector<int>& path, vector<vector<int>>& result )
        {
            if(count == k)
            {
                result.push_back(path);
            }
            else
            {
                for(int i = cur; i < n; ++i)
                {
                    path.push_back(i);
                    helper(i + 1, count + 1, n , k, path, result);
                    path.pop_back();
                }
            }
        }
};
