752. Open the Lock
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        //这题，不用多想，必是搜索，但是怎么去搜，如何剪枝，需要考虑
        unordered_set<string> help(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;

        string init = "0000";
        visited.insert(init);
        if(help.find(init) != help.end())   return -1;
        q.push(init);
        int res = 0;

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                string s = q.front();
                q.pop();
                vector<string> stringset = GenerateStr(s);
                for(auto temp : stringset)
                {
                    if(temp == target)  return ++res;
                    if(visited.find(temp) != visited.end())   continue;
                    if(help.find(temp) == help.end())
                    {
                        visited.insert(temp);
                        q.push(temp);
                    }
                }
            }
            ++res;
        }
        return -1;
    }

    vector<string> GenerateStr(string input)
    {
        vector<string> out;
        for(int i = 0; i < 4; ++i)
        {
            string tmp = input;
            tmp[i] = int((input[i] - '0' + 1) % 10) + '0';
            out.push_back(tmp);
            tmp[i] = int((input[i] - '0' + 9) % 10) + '0';
            out.push_back(tmp);
        }
        return out;
    }
};
