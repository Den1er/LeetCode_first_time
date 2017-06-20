557	Reverse Words in a String III
//考虑每次遇到一个空格以及最后一个元素的情况
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty() || s.size() == 1)   return s;
        int begin = 0, end = 0;
        for(int i = 0; i < s.size(); ++i) 
        {
           if(s[i] == ' ' || i == s.size() - 1) 
           {
               if(i == s.size() - 1)
                   end = i;
               else
                   end = i - 1;
               swapstr(s, begin, end);
               begin = i + 1;
           }
        }
        return s;
    }
    void swapstr(string s, int b, int e)
    {
        if(b >= e)  return;
        while(b + 1 <= e)
        {
            char tmp = s[b];
            s[b] = s[e];
            s[e] = tmp;
            ++b;
            --e;
        }
    }
};
