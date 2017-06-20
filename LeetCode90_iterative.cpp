394. Decode String
class Solution {
public:
    string decodeString(string s) {
        string tmp = "";
        stack<int> s_num;
        stack<string> s_str;
        int count = 0;
        int i = 0;
        while(i<s.size())
        {
            if(isdigit(s[i]))   count = 10*count + (s[i++]-'0');
            else if(s[i]=='[')
            {
                i++;
                s_num.push(count);
                s_str.push(tmp);
                count = 0;
                tmp.clear();
            }
            else if(s[i]==']')
            {
                i++;
                for(int j = 0; j<s_num.top(); ++j)
                {
                    s_str.top()+=tmp;
                }
                tmp = s_str.top();
                s_num.pop();
                s_str.pop();
            }
            else
            {
                tmp+=s[i++];
            }
        }
        return s_str.empty()?tmp:s_str.top();
    }
    
};