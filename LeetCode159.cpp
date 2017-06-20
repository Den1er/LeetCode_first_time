582. Kill Process
//层序遍历搜索整棵树，之前使用的是深度优先搜索，在这种数据下很慢
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i < ppid.size(); ++i)
        {
            hash[ppid[i]].push_back(pid[i]);
        }
        queue<int> que;
        que.push(kill);
        while(!que.empty())
        {
            res.push_back(que.front());
            int store = que.front();
            que.pop();
            for(int i = 0; i < hash[store].size(); ++i)
            {
                que.push(hash[store][i]);
            }
        }
        return res;
    }
};
