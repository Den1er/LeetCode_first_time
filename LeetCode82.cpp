58. Length of Last Word
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int len = s.size();
        while(len)
        {
            if(s[len-1]!=' ')
            {
                ++count;
                --len;
            }
            else if(count==0&&s[len-1]==' ')
            {
                --len;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};
