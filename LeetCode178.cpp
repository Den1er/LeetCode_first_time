332. Reconstruct Itinerary
//这道题非常非常地重要，因为我想不到这个bottom-up的解法，真的很难受
//解法的核心是，出度为0的点直接放入res中，如果哪条有向边使用过，直接删除
//还有一个要点是mulitiset的作用是给字符串排序，并且可以存在不同的元素
class Solution {
public:
    void DFS(string str)
    {
        while(hash[str].size() > 0)
        {
            string tem = *hash[str].begin();
            hash[str].erase(hash[str].begin());
            DFS(tem);
        }
        result.push_back(str);
    }
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        if(tickets.size() ==0) return {};
        for(auto val: tickets) hash[val.first].insert(val.second);
        DFS("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
private:
    vector<string> result;
    unordered_map<string, multiset<string>> hash;
};
