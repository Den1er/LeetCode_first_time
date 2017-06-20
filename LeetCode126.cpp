529. Minesweeper
//仔细想还是会做的
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        if(board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        helper(board, x, y);
        return board;
    }
    void helper(vector<vector<char>>& board, int x, int y)
    {
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        for(signed int i = -1; i < 2; ++i)
        {
            for(signed int j = -1; j < 2; ++j)
            {
                if(i + x > -1 && i + x < n && y + j > -1 && y + j < m && board[x + i][y + j] == 'M')
                    ++count;
            }
        }
        if(count != 0)
        {
            board[x][y] = char('0' + count);
            return;
        }
        else
        {
            board[x][y] = 'B';
            for(signed int i = -1; i < 2; ++i)
            {
                for(signed int j = -1; j < 2; ++j)
                {
                    if(i + x > -1 && i + x < n && y + j > -1 && y + j < m && board[x + i][y + j] == 'E')
                        helper(board, i + x, j + y);
                }
            }
            return;
        }
    }
};