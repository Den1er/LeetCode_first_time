463. Island Perimeter
//这跟哈希表有啥关系啊，晕
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();        
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    if(j == 0 ||  grid[i][j - 1] == 0) count++;
                    if(i == 0 || grid[i - 1][j] == 0)   count++;
                    if(j == n -1 || grid[i][j + 1] == 0)    count++;
                    if(i == m - 1 || grid[i + 1][j] == 0)   count++;
                }
            }
        }
        return count;
    }
};

