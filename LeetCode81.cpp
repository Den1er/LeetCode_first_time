20. Valid Parentheses
经验不足还是，括号问题是典型的栈应用
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> sta;
        for(int i = 0; i<len; ++i)
        {
            if(s[i]=='{'||s[i]=='['||s[i]=='(')
                sta.push(s[i]);
            else
            {
                if(sta.empty())
                    return false;
                if(s[i]=='}'&&sta.top()=='{'||s[i]==']'&&sta.top()=='['||s[i]==')'&&sta.top()=='(')
                    sta.pop();
                else
                    return false;
            }
        }
        if(!sta.empty())
            return false;
        else
            return true;
    }
};