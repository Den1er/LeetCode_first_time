258. Add Digits
class Solution {
public:
    int addDigits(int num) {
        if(num<10)  return num;
        int re = 0;
        while(num)
        {
            re += num%10;
            num /=10;
        }
        return addDigits(re);
    }
};