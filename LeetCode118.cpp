242. Valid Anagram
//哈希表
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size() )       return 0;
        unordered_map<char, int> map;
        for(int i = 0; i < s.size(); ++i)
        {
            unordered_map<char, int>::iterator it;
            if((it = map.find(s[i])) == map.end())
                map[s[i]] = 1;
            else
                map[s[i]]++;
        }
        for(int i = 0; i < t.size(); ++i)
        {
            unordered_map<char, int>::iterator it;
            if((it = map.find(t[i])) != map.end())
            {
                map[t[i]]--;
            }
            else
            {
                return 0;
            }
        }
        unordered_map<char, int>::iterator it;
        for(it = map.begin(); it != map.end(); ++it)
        {
            if(it->second != 0)
                return 0;
        }
        return 1;
    }
};