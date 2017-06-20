121. Best Time to Buy and Sell Stock
//比较简单的DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int globalmax = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(prices[i] - prices[j] > globalmax)
                    globalmax = prices[i] - prices[j];
            }
        }
        return globalmax;
    }
};

//以为比较简单，一看运行时间，就知道自己想到的是个很笨的方法，于是上网查了一下。。。。。。。。。。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int globalmax = 0;
        if(prices.size() == 0)  return globalmax;
        int lowestprice = prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] < lowestprice)
                lowestprice = prices[i];
            else
                globalmax = (prices[i] - lowestprice) > globalmax ? (prices[i] - lowestprice) : globalmax;
        }
        return globalmax;
    }
};