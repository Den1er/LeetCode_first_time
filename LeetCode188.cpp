720. Longest Word in Dictionary
class Solution {
public:
    string longestWord(vector<string>& words) {
        string result = "";
        int count = 0;
        unordered_set<string> data(words.begin(), words.end());

        queue<string> q;
        for(int i = 0; i < words.size(); ++i)
        {
            if(words[i].size() == 1)    q.push(words[i]);
        }

        while(!q.empty())
        {
            string tmp = q.front();
            q.pop();
            if(tmp.size() > count)
            {
                result = tmp;
                count = tmp.size();
            }
            else if(tmp.size() == count)
            {
                if(tmp < result)    result = tmp;
            }

            for(char c = 'a'; c <= 'z'; ++c)
            {
                tmp.push_back(c);
                if(data.count(tmp))  q.push(tmp);
                tmp.pop_back();
            }
        }
        return result;
    }
};
