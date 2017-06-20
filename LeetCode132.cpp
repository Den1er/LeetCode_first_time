434. Number of Segments in a String
//isempty代表前一个数是不是' '，只有前一个为空，当前值非空的时候，计数器自加
class Solution {
public:
    int countSegments(string s) {
        bool isempty = 1;
        int res = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(isempty && s[i] != ' ')
            {
                ++res;
                isempty = 0;
            }
            if(!isempty && s[i] == ' ')
                isempty = 1;
        }
        return res;
    }
};