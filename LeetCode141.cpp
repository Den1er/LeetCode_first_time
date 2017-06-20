120. Triangle
//动态规划，详解在evernote上
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> store = triangle;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < store[i].size(); ++j)
                store[i][j] = -1;
        }
        return dfs(0, 0, store, triangle);
        
    }
    int dfs(int x, int y,vector<vector<int>>& store,vector<vector<int>>& array)
    {
        if(x >= store.size())
            return 0;
        if(store[x][y] != -1)
            return store[x][y];
        store[x][y] = min(dfs(x + 1, y, store, array), dfs(x + 1, y + 1, store, array)) + array[x][y];
        return store[x][y];
    }
};
