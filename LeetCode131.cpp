9. Palindrome Number
//需要注意最大整型
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)   return 0;
        long int n = 1;
        while(x / (n * 10) != 0)
        {
            n *= 10;
        }
        while(x > 0)//这个条件很重要   例如1000021
        {
            /*cout<<"x="<<x<<endl;
             cout<<"n="<<n<<endl;
             */
            if(x / n != x % 10)
                return 0;
            x %= n;
            x /= 10;
            n /= 100;
        }
        return 1;
    }
};