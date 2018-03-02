127. Word Ladder
//本题解法采用BFS，类似层序遍历，访问过的元素直接从字典删除
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 1;
        queue<string> q;
        unordered_set<string> uset(wordList.begin(), wordList.end());
        q.push(beginWord);

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                string s = q.front();
                q.pop();
                vector<string> set = FormSet(s, uset);
                for(auto word : set)
                {
                    if(word == endWord) return ++res;
                    if(isValid(s, word))
                    {
                        q.push(word);
                        uset.erase(word);
                    }

                }
            }
            ++res;
        }
        return 0;
    }

    vector<string> FormSet(string input, unordered_set<string>& wordList)
    {
        vector<string> res;
        for(auto word : wordList)
            if(isValid(input, word))    res.push_back(word);
        return res;
    }

    bool isValid(string input, string word)
    {
        int cnt = 0;
        int size = input.size();
        for(int i = 0; i < size; ++i)
        {
            if(input[i] != word[i]) cnt++;
            if(cnt > 1) return 0;
        }
        return cnt == 1 ? 1 : 0;
    }
};
