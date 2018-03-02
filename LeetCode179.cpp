576. Out of Boundary Paths
//想了半天想不出来的动态规划，而且还是基础题。。。。。。
//状态的含义是走了由i, j走了step步达到x, y的路径可能性
//递推公式是从dp[step][i][j] += dp[step - 1][i + dx][j + dy]
//如果到界外就在res上加起来
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int axili[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int dp[51][51][51] = {0};
        dp[0][i][j] = 1;
        int res = 0;
        const int DATA = 1000000007;
        for(int step = 1; step <= N; ++step)
            for(int x = 0; x < m; ++x)
                for(int y = 0; y < n; ++y)
                    for(int tralor = 0; tralor < 4; ++tralor)
                    {
                        int nx = x + axili[tralor][0];
                        int ny = y + axili[tralor][1];
                        if(nx < 0 || nx >= m || ny < 0 || ny >=n)
                            res = (res + dp[step - 1][x][y]) % DATA;
                        else
                            dp[step][x][y] = (dp[step][x][y] + dp[step - 1][nx][ny]) % DATA;
                    }
        return res;
    }
};
