202. Happy Number
//算法是如果各个位置的平方和不等于1，那么一定会陷入一个循环中，我们只需将已算出来的结果存在哈希表里，那么只要出现了重复的数字，就一定不满足要求
class Solution {
public:
    bool isHappy(int n) {
        if(n == 1)
            return 1;
        unordered_map<int, int> map;
        while(map.find(n) == map.end()) 
        {
           if(getsquare(n) == 1) 
               return 1;
           else
           {
               map[n] = 1;
           }
           n = getsquare(n);
        }
        return false;
    }
    int getsquare(int n) 
    {
        int num = 0;
        while(n > 0)       
        {
            num += (n % 10) * (n % 10);
            n /= 10;
        }
        return num;
    }
};
