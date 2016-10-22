130. Surrounded Regions
超时的做法，宝宝想出来的，很不容易啦
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0||board[0].size()==0) return;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<n; ++i)
        {
            if(board[0][i]=='O')
            {
                dfs(board, 0, i);
            }
        }
        for(int i = 0; i<n; ++i)
        {
            if(board[m-1][i]=='O')
            {
                dfs(board, m-1, i);
            }
        }
        for(int i =1; i<m; ++i)
        {
            if(board[i][0]=='O')
            {
                dfs(board, i, 0);
            }
        }
        for(int i = 0; i<m;++i)
        {
            if(board[i][n-1]=='O')
            {
                dfs(board, i, n-1);
            }
        }
        for(int i = 0; i<m; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'R')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        board[i][j] = 'R';
        if(i>0&&board[i-1][j]=='O')
        {
            dfs(board, i-1, j);
        }
        if((i<board.size()-1)&&board[i+1][j]=='O')
        {
            dfs(board, i+1, j);
        }
        if(j>0&&board[i][j-1]=='O')
        {
            dfs(board, i, j-1);
        }
        if(j<board[0].size()&&board[i][j+1]=='O')
        {
            dfs(board, i, j+1);
        }
    }
};