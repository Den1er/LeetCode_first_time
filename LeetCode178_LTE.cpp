class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        tmpres.push_back("JFK");
        vector<bool> visited(tickets.size(), 0);
        dfs(tickets, visited, tmpres);
        return res;
    }
private:
    vector<string> res;
    vector<string> tmpres;
    void  dfs(vector<pair<string, string>>& tickets, vector<bool> visited, vector<string> tmpres)
    {
        int m = tickets.size();
        if(tmpres.size() == m + 1)
        {
            if(res.empty()) res = tmpres;
            else
            {
                for(int i = 0; i < res.size(); ++i)
                {
                    if(tmpres[i] == res[i]) continue;
                    if(tmpres[i] > res[i])  break;
                    if(tmpres[i] < res[i])
                    {
                        res = tmpres;
                        break;
                    }
                }
            }
        }
        string tmp = "ZZZ";
        for(int i = 0; i < m; ++i)
        {
            if(visited[i] == 1) continue;
            if(tickets[i].first == tmpres[tmpres.size() - 1])
            {
                tmp = tickets[i].second;
                visited[i] = 1;
                tmpres.push_back(tmp);
                dfs(tickets, visited, tmpres);
                visited[i] = 0;
                tmpres.resize(tmpres.size() - 1);
            }
        }
    }
};
