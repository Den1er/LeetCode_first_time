37. Sudoku Solver
//一天的时间花在这上，告诫自己，不要理所应当，不要忽视小细节
//1、用Int和char比较相等，永远不会相同
//2、算的值没用上，你也没发现，你真蠢
class Solution {
public:
    int count;
    void solveSudoku(vector<vector<char>>& board) {
        int answer = dfs(board, 0);
        //cout<<answer;
        //cout<<count;
    }
    bool dfs(vector<vector<char>>& board, int pos)
    {
        int row = pos / 9;
        int col = pos % 9;
        if(pos == 81)
        {
            return true;
        }
        if(board[row][col] == '.')
        {
            for(int i = 1; i < 10 ; ++i)
            {
                if(helper(board, pos, i + '0'))
                {
                    //cout<<i<<endl;
                    board[row][col] = i + '0';
                    if(dfs(board, pos + 1))
                        return true;
                    board[row][col] = '.';
                }
            }
        }
        else
        {
            if(dfs(board, pos + 1))
                return true;
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, int pos, char num)
    {
        int row = pos / 9;
        int col = pos % 9;
        
        int grid;
        
        if(row >= 0 && row <= 2)
        {
            if(col < 3)
                grid = 0;
            else if(col > 5)
                grid = 2;
            else
                grid = 1;
        }
        else if(row >= 3 && row <= 5)
        {
            if(col < 3)
                grid = 3;
            else if(col > 5)
                grid = 5;
            else
                grid = 4;
        }
        else
        {
            if(col < 3)
                grid = 6;
            else if(col > 5)
                grid = 8;
            else
                grid = 7;
        }
        // cout<<row<<'\t'<<col<<endl;
        for(int i = 0; i < 9 ; ++i)
        {
            
            if(i != col && num == board[row][i])
            {
                
                return false;
            }
            if(i != row && num == board[i][col])
                return false;
            int r = grid / 3 * 3 + i / 3;
            int c = grid % 3 * 3 + i % 3;
            if((r != row || c != col) && num == board[r][c])
                return false;
        }
        return true;
    }
};