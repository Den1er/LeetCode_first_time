class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i < ppid.size(); ++i)
        {
            hash[ppid[i]].push_back(pid[i]);
        }
        res.push_back(kill);
        dfs(hash, pid, ppid, res, kill);
        return res;
    }
    void dfs(unordered_map<int, vector<int>> hash, vector<int>& pid, vector<int>& ppid, vector<int>& res, int val)
    {
        for(int i = 0; i < hash[val].size(); ++i)
        {
                res.push_back(hash[val][i]);
                dfs(hash, pid, ppid, res, hash[val][i]);
        }
    }
};
