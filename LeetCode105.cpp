51. N-Queens
//超时版本
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board;
        string s;
        for(int i = 0; i < n; ++i)
        {
            s += '.';
        }
        for(int i = 0; i < n; ++i)
        {
            board.push_back(s);
        }
        dfs(0, n, board, result);
        return result;
    }
    void dfs(int now, int n, vector<string>& board, vector<vector<string>>& result)
    {
        if(now == n)
        {
            result.push_back(board);
            return;
        }
        for(int i = 0; i < n; ++i)
        {
            if(clash(now, i,n, board))
            {
                board[now][i] = 'Q';
                dfs(now + 1, n, board, result);
                board[now][i] = '.';
            }
        }
    }
    bool clash(int now, int col ,int n, vector<string>& board)
    {
        for(int i =0; i < now; ++i)
        {
            if(board[i][col] == 'Q')
            {
                return 0;
            }
        }
        for(int i = now, j = col; i >= 0 , j >= 0; --i, --j)
        {
            if(board[i][j] == 'Q')
                return 0;
        }
        for(int i = now, j = col; i >= 0, j < n; --i, ++j)
        {
            if(board[i][j] == 'Q')
                return 0;
        }
        return 1;
    }
};