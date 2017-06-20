93. Restore IP Addresses
//本题需注意两点，0.0.0.0成立，但是00.002这样的不成立。计算数值num的时候指的借鉴
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> tmp;
        dfs(tmp, result, s, 0);
        return result;
    }
    void dfs(vector<string>& tmp, vector<string>& result, const string& s, int begin)
    {
        if(tmp.size() == 4 && begin == s.size())
        {
            result.push_back(tmp[0] + '.' + tmp[1] + '.' + tmp[2] + '.' + tmp[3]);
            return;
        }
        if(s.length() - begin > 3 * (4 - tmp.size()))       //剪枝
            return;
        int num = 0;
        for(int i = begin; i < begin + 3 && i < s.size() ; ++i)
        {
            num = num * 10 + int(s[i] - '0');
            
            if(num > 255)
                return;
            
            string str = s.substr(begin, i - begin + 1);
            if(str[0] == '0' && str.size() > 1)
                return;
            
            tmp.push_back(str);
            dfs(tmp, result, s, i + 1);
            tmp.pop_back();
        }
    }
};