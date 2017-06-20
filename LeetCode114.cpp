417. Pacific Atlantic Water Flow
//本题的题意我一开始就没搞懂，看了网上的题意分析和解法之后自己写的，其中的BUG出在x,y坐标的含义上，以后一定要想清楚再写
class Solution {
public:
    vector<int> x_label = {0, 0, -1, 1};
    vector<int> y_label = {-1, 1, 0, 0};
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if(matrix.size() == 0)  return result;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> matrix_pacific(m, vector<bool>(n)), matrix_atlantic(m, vector<bool>(n));
        for(int i = 0; i < m; ++i)
        {
            search(matrix, matrix_pacific, i, 0, m, n);
            search(matrix, matrix_atlantic, i, n - 1, m, n);
        }
        for(int i = 0; i < n; ++i)
        {
            search(matrix, matrix_pacific, 0, i, m, n);
            search(matrix, matrix_atlantic, m - 1, i, m, n);
        }
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n;++j)
            {
                if(matrix_pacific[i][j] == 1 && matrix_atlantic[i][j] == 1)
                {
                    pair<int, int> temp =  make_pair(i, j);
                    result.push_back(temp);
                }
            }
        }
        return result;
        
    }
    void search(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int x, int y, int m, int n)
    {
        ocean[x][y] = 1;
        for(int i = 0; i < 4; ++i)
        {
            int x_now = x + x_label[i];
            int y_now = y + y_label[i];
            if(x_now > -1 && x_now < m && y_now > -1 && y_now < n && matrix[x][y] <= matrix[x_now][y_now] && ocean[x_now][y_now] == 0)
            {
                search(matrix, ocean, x_now, y_now, m, n);
            }
        }
    }
};