357. Count Numbers with Unique Digits
//排列组合题目
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int result = 0;
        for(int i = 0; i < n; ++i)
        {
            result += helper(i + 1);
        }
        return result;
    }
    int helper(int n)
    {
        if(n == 1)
        {
            return 10;
        }
        else if(n == 2)
        {
            return 81;
        }
        else if(n > 10)
        {
            return helper(10);
        }
        else
        {
            return helper(n-1) * (11 - n);
        }
    }
};