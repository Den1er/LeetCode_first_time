541. Reverse String II
//字符串逆序的翻版
class Solution {
public:
    string reverseStr(string s, int k) {
       if(s.size() <= k) 
       {
           exchange(s, 0, s.size() - 1);
           return s;
       }
       else if(s.size() > k && s.size() <= 2 * k)       
       {
           exchange(s, 0, k - 1);
           return s;
       }
       else
       {
           string substring = s.substr(0, 2 * k);
           exchange(substring, 0, k - 1);
           return substring + reverseStr(s.substr(2 * k), k);
       }
    }
    void exchange(string& s, int start, int end)
    {
        while(start + 1 <= end)
        {
            char med = s[start];
            s[start++] = s[end];
            s[end--] = med;
        }
    }
};
