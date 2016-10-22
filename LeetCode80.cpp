10. Regular Expression Matching
这题花了很久的时间在看答案
问题1：*符号的作用是匹配前一个或者0个或者多个字符
问题2：c_str()函数：一个将string转换为 const* char的函数，形参部分一定要写成const 的指针，否则runtime error
class Solution {
public:
    bool isMatch(string s, string p) {
        return   isMatch(s.c_str(),p.c_str());
    }
    bool isMatch(const char *s, const char *p)
    {
        if(*p=='\0') return *s=='\0';
        if(*(p+1)!='*')
        {
            if(*p==*s||(*p == '.' && *s != '\0'))
            {
                return isMatch(s+1,p+1);
            }
            else
            {
                return false;
            }
        }
        else
        {
            while(*p==*s||(*p == '.' && *s != '\0'))
            {
                if(isMatch(s,p+2))
                {
                    return true;
                }
                ++s;
            }
            return isMatch(s,p+2);
        }
    }
};