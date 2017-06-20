52. N-Queens II
//做一题送一题类型的
class Solution {
        public:
        int count = 0;
        int totalNQueens(int n) {
            vector<vector<string>> result;
        vector<string> board;
        vector<int> check(n, -1);
        string s;
        for(int i = 0; i < n; ++i)
        {
            s += '.';
        }
        for(int i = 0; i < n; ++i)
        {
            board.push_back(s);
        }
        dfs(0, n, board, result,check);
        return count;
    }
    void dfs(int now, int n, vector<string>& board, vector<vector<string>>& result, vector<int> check)
    {
        if(now == n)
        {
            result.push_back(board);
            ++count;
            return;
        }
        for(int i = 0; i < n; ++i)
        {
            if(clash(now, i,n, board , check))
            {
                board[now][i] = 'Q';
                check[now] = i;
                dfs(now + 1, n, board, result,check);
                board[now][i] = '.';
            }
        }
    }
    bool clash(int now, int col ,int n, vector<string>& board, vector<int> check)
    {
        for(int i = 0; i < now; ++i)
        {
            if(check[i] == col || abs(now - i) == abs(col - check[i]))
            {
                return 0;
            }
        }
        return 1;
    }
};
