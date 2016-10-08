389. Find the Difference
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res;
        for(int i = 0;i<s.length();i++)
        {
            res = char(res ^ s[i]);
        }
        for(int i = 0;i<t.length();i++)
        {
            res = char(res ^ t[i]);
        }
        return res;
    }
};