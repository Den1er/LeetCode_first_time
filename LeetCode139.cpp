28. Implement strStr()
//注意一些边界条件
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() == 0 && needle.size() != 0 || haystack.size() < needle.size())    return -1;
        if(haystack == needle)  return 0;
        
        int length = needle.size();
        for(int i = 0; i < haystack.size() - length + 1; ++i)
        {
            string sub = haystack.substr(i, length);
            //cout<<sub<<endl;
            if(sub == needle)
                return i;
        }
        return -1;
    }
};