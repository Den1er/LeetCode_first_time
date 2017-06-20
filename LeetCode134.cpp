49. Group Anagrams
//给每一个字符串排序，并且把排序之后结果相同的字符串合并到同一个哈希表里，学着点
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>   m;
        for(int i = 0; i < strs.size(); ++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(strs[i]);
        }
        vector<vector<string>>  res;
        for(auto i = m.begin(); i != m.end(); ++i)
        {
            res.push_back(i->second);
        }
        return res;
    }
};