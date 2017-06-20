459. Repeated Substring Pattern
//一点一点匹配
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //bool ret = 0;
        for(int i = 1;i <= s.length()/2; ++i){
            if(s.length() % i) continue;
            string sub = s.substr(0, i);
            int j = 0;
            while(j < s.length())
            {
                if(s[j] != sub[j % i])
                    break;
                ++j;
            }
            if(j == s.length())
                return 1;
        }
        return 0;
    }
};
