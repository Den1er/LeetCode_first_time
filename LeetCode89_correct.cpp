130. Surrounded Regions
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0||board[0].size()==0) return ;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i<m; ++i)
        {
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][n-1]=='O')
                dfs(board,i,n-1);
        }
        for(int j = 0; j<n;++j)
        {
            if(board[0][j]=='O')
                dfs(board,0,j);
            if(board[m-1][j]=='O')
                dfs(board,m-1,j);
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
        stack<pair<int,int>> s;
        s.push(make_pair(i,j));
        while(!s.empty())
        {
            int i = s.top().first;
            int j = s.top().second;
            board[i][j] = 'R';
            s.pop();
            if(i>0&&board[i-1][j]=='O')   s.push(make_pair(i-1,j));
            if((i<board.size()-1)&&board[i+1][j]=='O')    s.push(make_pair(i+1,j));
            if(j>0&&board[i][j-1]=='O')   s.push(make_pair(i,j-1));
            if((j<board[0].size()-1)&&board[i][j+1]=='O')    s.push(make_pair(i,j+1));
        }
    }
};