547. Friend Circles
//难得的一次跑通，思路是设置一个visited数组，每次访问一个未被访问的元素就深搜完他的所有朋友，并且设置成visited
//访问到未被访问的元素，res+1
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        const int m = M.size();
        vector<int> visited(m, 0);
        res = 0;
        for(int i = 0; i < m; ++i)
        {
            if(visited[i] == 1) continue;
            ++res;
            dfs(i, M, visited);
        }
        return res;
    }
private:
    int res;
    void dfs(int i, const vector<vector<int>>& M, vector<int>& visited )
    {
        const int m = M.size();
        for(int j = 0; j < m; ++j)
        {
            if(i == j || M[i][j] == 0 || visited[j] == 1)  continue;
            if(visited[j] == 0)
            {
                visited[j] = 1;
                dfs(j, M, visited);
            }
        }
    }
};
