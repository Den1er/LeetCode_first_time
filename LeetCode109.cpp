131. Palindrome Partitioning
//从字符串的开头开始，一个字符一个字符地判断到底是不是回文串，是的话可以往下走，不是的话，终止这一次递归
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> tmp;
        if(s.size() == 0)
            return result;
        dfs(0, s, tmp, result);
        return result;
    }
    void dfs(int start, string& s, vector<string>& tmp, vector<vector<string>>& result)
    {
        if(start == s.size())
        {
            result.push_back(tmp);
            return;
        }
        for(int i = start; i < s.size(); ++i)
        {
            if(ispalindrome(s, start, i))
            {
                tmp.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, s, tmp, result);
                tmp.pop_back();
            }
        }
    }
    bool ispalindrome(string& s, int low, int hi)
    {
        while(low <= hi)
        {
            if(s[low++] != s[hi--])
            {
                return 0;
            }
        }
        return 1;
    }
};