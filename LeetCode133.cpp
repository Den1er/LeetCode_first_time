36. Valid Sudoku
//这道题是验证数独是否符合规范，而不是看有没有可行解的问题，因此，没必要用回溯去查看是否有解，只需符合规范~
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9 || board[0].size() != 9)
            return 0;
        for(int i = 0; i < 9; ++i)
        {
            vector<bool> used(9,0);
            for(int j = 0; j < 9; ++j)
            {
                if(!isdigit(board[i][j]))
                    continue;
                if(int(board[i][j] - '0') <= 0 || used[int(board[i][j] - '0') - 1])
                    return 0;
                used[int(board[i][j] - '0') - 1] = 1;
            }
        }
        for(int i = 0; i < 9; ++i)
        {
            vector<bool> used(9,0);
            for(int j = 0; j < 9; ++j)
            {
                if(!isdigit(board[j][i]))
                    continue;
                if(int(board[j][i] - '0') <= 0 || used[int(board[j][i] - '0') - 1])
                    return 0;
                used[int(board[j][i] - '0') - 1] = 1;
            }
        }
        for(int i = 0; i < 3; ++i )
        {
            for(int j = 0; j < 3; ++j)
            {
                vector<bool> used(9,0);
                for(int k = 0; k < 9; ++k)
                {
                    if(!isdigit(board[3 * i + k / 3][3 * j + k % 3]))
                        continue;
                    if(int(board[3 * i + k / 3][3 * j + k % 3] - '0') <= 0 || used[int(board[3 * i + k / 3][3 * j + k % 3] - '0') - 1])
                        return 0;
                    used[int(board[3 * i + k / 3][3 * j + k % 3] - '0') - 1] = 1;
                }
            }
        }
        return 1;
    }
};