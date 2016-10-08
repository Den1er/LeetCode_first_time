383. Ransom Note
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()==0)    return true;
        unordered_map<char,int> hash;
        for(int i = 0; i<magazine.size(); ++i)
        {
            ++hash[magazine[i]];
        }
        unordered_map<char,int>::iterator citor;
        for(int i = 0; i<ransomNote.size(); ++i)
        {
            citor = hash.find(ransomNote[i]);
            if(citor==hash.end()||citor->second==0)
            {
                return false;
            }
            else
            {
                --citor->second;
            }
            
        }
        return true;
    }
};