50. Pow(x, n)
//里面有两个需要注意的地方
//一个是最小负数INTEGER.MIN取负数的问题，正数最大无法表示到这个数，因此不能直接加负号，需要将其变小之后再取负号
//二个是C++里负数取余的问题，比如本题-3%2的结果是-1，在我的记忆里，取余运算应该找到一个比被余数n小的值m，用n-m得到余数，实际上不是这样的
class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        int t = n/2;
        if(n < 0)
        {
            t = -t;
            x = 1 / x;
        }
        
        double v = myPow(x, t);
        if(n % 2 == 0)
        {
            return v * v;
        }
        else
            return v * v * x;
        
    }
};