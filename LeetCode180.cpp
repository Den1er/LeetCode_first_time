688. Knight Probability in Chessboard
//又是一个自底向上的解法，没想到，将问题转化成从棋盘上的任意一点经过K步到达r,c点的问题
//状态state代表经过K步到达r,c 比较直观的一个方法是状态指方法数，K=0时初始化为0
class Solution {
        private:
        int helper[8][8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
        bool check(int i, int j, int N)
        {
            if((i < 0) || (j < 0) || (i > N - 1) || (j > N - 1)) return 0;
            return 1;
        }
        public:
        double knightProbability(const int N, const int K, const int r, const int c) {
            if(K == 0)  return 1;
            double state[K + 1][N][N];
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                {
                    state[0][i][j] = 1.0;
                }
            for(int i = 1; i < K + 1; ++i)
                for(int j = 0; j < N; ++j)
                    for(int k = 0; k < N; ++k)
                    {
                        state[i][j][k] = 0.0;
                    }

            for(int i = 1; i < K + 1; ++i)
                for(int j = 0; j < N; ++j)
                    for(int k = 0; k < N; ++k)
                        for(int l = 0; l < 8; ++l)
                        {
                            int new_j = j + helper[l][0];
                            int new_k = k + helper[l][1];
                            if(check(new_j, new_k, N))
                                state[i][j][k] += (state[i - 1][new_j][new_k] / 8.0);
                        }
            return state[K][r][c];
        }

};
