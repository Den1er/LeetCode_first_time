680. Valid Palindrome II
//比较笨的一个方法
class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size() < 3)    return 1;
        int c1 = 0;
        int c2 = 0;
        int l = 0;
        int r = s.size() - 1;
        while(l < r && c1 < 2)
        {
            if(s[l] != s[r])
            {
                ++c1;
                ++l;
            }
            else
            {
                ++l;
                --r;
            }
        }
        l = 0;
        r = s.size() - 1;
        while(l < r && c2 < 2)
        {
            if(s[l] != s[r])
            {
                ++c2;
                --r;
            }
            else
            {
                ++l;
                --r;
            }

        }
        return c1 < 2 || c2 < 2;
    }
};
