122. Best Time to Buy and Sell Stock II
//贪心算法，只要结果能变大就卖
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)  return 0;
        //int local = 0;
        int global = 0;
        for(int i = 0; i < prices.size() - 1; ++i)
        {
            if(prices[i + 1] > prices[i])   global += (prices[i + 1] - prices[i]);
        }
        return global;
    }
};
