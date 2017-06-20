394. Decode String
class Solution {
public:
    string decodeString(string s) {
        int k = 0;
        return dfs(s,k);
    }
    string dfs(string s, int& k)
    {
        int count = 0;
        string ans = "";
        while(k<s.size())
        {
            if(isdigit(s[k]))   count = count*10+(s[k++]-'0');
            else if(s[k]=='[')
            {
                ++k;
                string tmp = dfs(s, k);
                for(int i = 0; i<count; ++i)
                    ans+=tmp;
                count = 0;
            }
            else if(s[k]==']')
            {
                ++k;
                return ans;
            }
            else
            {
                ans+=s[k++];
            }
        }
        return ans;
    }
};

这个递归的方法很好，收藏了
class Solution {
public:
    string parse(string s) {
        string r = "";
        for(int i = 0; i < s.size();) {
            if(isdigit(s[i])) {
                int num = 0;
                while(isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                int bracket_match = 1;
                int j = i;
                while(bracket_match > 0) {
                    ++j;
                    if(s[j] == '[') ++bracket_match;
                    else if(s[j] == ']') --bracket_match;
                }
                string temp = parse(s.substr(i + 1, j - i - 1));
                for(int k = 0; k < num; ++k) {
                    r += temp;
                }
                i = j + 1;
            } else if(isalpha(s[i])) {
                r += s[i];
                ++i;
            }
        }
        return r;
    }
    string decodeString(string s) {
        return parse(s);
    }
};