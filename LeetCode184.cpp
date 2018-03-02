647. Palindromic Substrings
class Solution {
public:
    int countSubstrings(string s) {
        //思路：dp[i][i] = 1，dp[i][j] 取决于dp[i + 1][j - 1]与s[i]是否与s[j]相等
        int len = s.size();
        bool dp[1000][1000] = {0};
        int count = 0;
        //必须从后往前计算，否则先验知识没有计算出来，dp[i][j]的结果会出错
        //即一个上三角矩阵，从右下角开始计算结果
        for(int i = len - 1; i >= 0; --i)
        {
            for(int j = i; j < len; ++j)
            {
                if(s[i] != s[j])
                    dp[i][j] = 0;
                else
                {
                   if((dp[i][j] = isPal(dp, i , j )) == 1)
                       ++count;
                }
            }
        }
        
        return count;
    }
private:
    bool isPal(bool dp[][1000], int start, int end)
    {
        if(end - start <= 1)    return true;
        else
            return dp[start + 1][end - 1];
    }
};
