72. Edit Distance
//经典的二维DP问题，需要注意一个问题，就是字符串分割的时候，给定的状态数组是dis[m + 1][n + 1]，这么一来，每个分割线前面的元素编号
//就是word1[i - 1]   word2[j - 1]这样的数据
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dis[m + 1][n + 1];
        for(int i = 0; i <= m; ++i)
        {
            dis[i][0] = i;
        }
        for(int i = 0; i <= n; ++i)
        {
            dis[0][i] = i;
        }
        
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                //a = str1a   b = str2b
                if(word1[i - 1] == word2[j - 1])
                    dis[i][j] = dis[i - 1][j - 1];
                else
                {
                    dis[i][j] = 1 + min(min(dis[i - 1][j - 1], dis[i - 1][j]), dis[i][j - 1]);
                }
            }
        }

        return dis[m][n];
    }
};