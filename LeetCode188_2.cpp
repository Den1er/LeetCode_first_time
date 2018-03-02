class Solution {
public:
    string longestWord(vector<string>& words) {
        string result = "";
        int count = 0;
        unordered_set<string> data(words.begin(), words.end());

        for(int i = 0; i < words.size(); ++i)
        {
            if(word[i].size() == 1) dfs(data, word[i], result, count);
        }
        return result;
    }

    void dfs(unordered_set<string>& data, string word, string& result, int& count)
    {
        if(word.size() > count)
        {
            result = word;
            count = word.size();
        }
        else if(word.size() == count)
        {
            if(word < result)   result = word;
        }

        for(char c = 'a'; c < 'z'; ++c)
        {
            word.push_back(c);
            if(data.count(word))    dfs(data, word, result, count);
            word.pop_back(c);
        }
    }
};
