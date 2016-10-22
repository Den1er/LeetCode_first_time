14. Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)  return strs[0];
        if(strs.size()==0)  return "";
        string prefix("");
        int cmp_num = INT_MAX;
        for(int i = 0; i<strs.size(); ++i)
        {
            if(strs[i].size()<cmp_num)
            {
                cmp_num = strs[i].size();
            }
        }
        //if(cmp_num==0)  return "";
        int i = 0;
        int count = 1;
        while(cmp_num)
        {
            for(int j = 1; j<strs.size(); ++j)
            {
                if(strs[0][i]==strs[j][i])
                    count++;
            }
            if(count==strs.size())
            {
                prefix.append(1,strs[0][i++]);
                count = 1;
                --cmp_num;
            }
            else
            {
                break;
            }
        }
        return prefix;
    }
};