3. Longest Substring Without Repeating Characters
//思路是如果没有遇到重复的，就r++，遇到了就从之前的字符串中找到这个重复的元素，以这个位置作为l，重新构建字符串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())   return 0;
        int maxlen = 1;
        int l = 0;
        int r = 0;

        int i = 0;
        while(++i < s.size())
        {
            string tmp = s.substr(l, r - l + 1);
            int tag;
            if(string::npos != tmp.find(s[i]))  
            {
                tag = tmp.find(s[i]);
                l = l + tag + 1;
                r = r + 1;
            }
            else
            {
                r = r + 1;
                if(r - l + 1 > maxlen)
                    maxlen = r - l + 1;
            }
        }
        return maxlen;

    }
};
