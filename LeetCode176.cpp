638. Shopping Offers
//这道题有些问题，既然是special offer,还会出现不优惠的情况，那个结果不太合理。
//我的做法是假设所有sp offer都会更优惠，先遍历所有的sp offer组合，不够的用单个补充，这个想法很不错。满足大部分情况
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        min = 0;
        for(int i = 0; i < needs.size(); ++i)
        {
            min += needs[i] * price[i];
        }
        dfs(price, special, needs, 0);
        return min;
    }
private:
    int min;
    void dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cur)
    {
        int m = special.size();
        int cnt = 0;
        for(int i = 0; i < m; ++i)
        {
            int n = needs.size();
            bool flag = 1;
            for(int j = 0; j < n; ++j)
            {
               if(needs[j] < special[i][j])
               {
                   flag = 0;
                   ++cnt;
                   break;
               }
            }
            if(flag == 1)
            {
                for(int j = 0; j < n; ++j)
                {
                    needs[j] -= special[i][j];
                }
                dfs(price, special, needs, cur + special[i][n]);
                for(int j = 0; j < n; ++j)
                {
                    needs[j] += special[i][j];
                }
            }
        }
        if(cnt == m)
        {
            for(int i = 0; i < needs.size(); ++i)
            {
                cur += needs[i] * price[i];
            }
            min = (min < cur ? min : cur);
        }
    }
};
