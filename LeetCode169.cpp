151. Reverse Words in a string
//这题条件说得不清不楚的，题目要求是，把所有字符串中的单词倒一个序，并且，所有的单词之间
//思路是在原串上直接修改（比较值得借鉴的思路），首先把字符串整体倒序
//接下来，设置一个Index,记录修改到哪一位
//从头到尾比遍历字符串，每次处理一个单词。若是第一个出现的单词，则不需要加空格。
//之后出现的单词先添加空格，再倒序插入单词
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int index = 0, n = s.size();
        for(int i = 0; i < n; ++i)
        {
            if(s[i] != ' ')
            {
                if(index != 0)
                    s[index++] = ' ';
                int j = i;
                while(j < n && s[j] != ' ')
                    s[index++] = s[j++];
                reverse(s.begin() + index - (j - i), s.begin() + index);
                i = j;
            }
        }
        s.resize(index);
    }
};
