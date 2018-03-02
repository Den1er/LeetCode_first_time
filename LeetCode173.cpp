542. 01 matrix
//正确的解法是BFS，这个解法类似于最短路径，从0出发，向周围探索，如果周围的节点值比自己大1以上，那么更新数据，是一个动态规划的思想
//这道题以后要经常看一看
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    q.push(make_pair(i, j));
                }
                else
                {
                    matrix[i][j] = INT_MAX;
                }
            }

        }
        while(!q.empty())
        {
            pair<int, int> tmp = q.front();
            q.pop();
            int x = tmp.first, y = tmp.second;
            for(int i = 0; i < 4; ++i)
            {
                int cx = x + a[i], cy = y + b[i];
                if(cx < 0 || cx >= m || cy < 0 || cy >= n   )   continue;
                if(matrix[cx][cy] <= matrix[x][y] + 1)  continue;
                matrix[cx][cy] = matrix[x][y] + 1;
                q.push(make_pair(cx, cy));
            }
        }
        return matrix;
    }
private:
    int a[4] = {1, -1, 0, 0};
    int b[4] = {0, 0, -1, 1};
};
