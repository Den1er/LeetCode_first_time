646. Maximum Length of Pair Chain
//本题DP的思路较容易想到，但是排序的操作没有想到，以及int dp[n] = {1}这句话的结果竟然不是把所有的元素全部置为1，我震惊了
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), copmpare);
        
        int n = pairs.size();
        int res  = 1;
        int dp[n] = {};
        for(int i = 0; i < n; ++i)
        {
            dp[i] = 1;
        }
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if((pairs[j][1] < pairs[i][0]) && (dp[i] <= dp[j] + 1))
                {
                    dp[i] = dp[j] + 1;
                    res = max(res, dp[i]);
                }
            }
        }
        
        return res;
    }

    static bool copmpare(const vector<int> a, const vector<int> b)
    {
        return a[0] < b[0];
    }
};
