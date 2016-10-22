38. Count and Say
学到的int char互相转换很重要
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(--n)
        {
            s = helper(s);
        }
        return s;
    }
    string int_to_string(int n)
    {
        stringstream s;
        string res;
        s<<n;
        s>>res;
        return res;
    }
    string helper(string s)
    {
        string res("");
        int count = 1;
        int i = 0;
        while(i<s.size())
        {
            while(i+count<s.size()&&s[i]==s[i+count])
            {
                ++count;
            }
            res += int_to_string(count);
            res.append(1,s[i]);
            i += count;
            count = 1;
        }
        return res;
    }
};