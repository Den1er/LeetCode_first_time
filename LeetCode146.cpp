139. Word Break
//DP，状态值为前i个字符能否拆分(break)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int MAX_WORD_LEN = getMaxLen(wordDict);
        bool canBreak[s.size() + 1];
        canBreak[0] = 1;
        for(int i = 1; i <= s.size(); ++i)
        {
            canBreak[i] = 0;
            for(int j = 1; j <= MAX_WORD_LEN && i - j >= 0; ++j)
            {
                if(canBreak[i - j] )
                {
                    string sub = s.substr(i - j, j );
                    if(containWord(sub, wordDict))
                    {
                        canBreak[i] = 1;
                        break;
                    }
                }
            }
        }
        return canBreak[s.size()];
    }
    int getMaxLen(vector<string>& wordDict)
    {
        int res = 0;
        for(int i = 0; i < wordDict.size(); ++i)
        {
            if(wordDict[i].size() > res)
                res = wordDict[i].size();
        }
        return res;
    }
    bool containWord(string s, vector<string>& wordDict)
    {
        for(int i = 0; i < wordDict.size(); ++i)
        {
            if(s == wordDict[i])
                return 1;
        }
        return 0;
    }
};