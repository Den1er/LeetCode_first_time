class Solution {
public:
    string reverseString(string s)
    {
        string n = "";
        int l = s.length();
        for(int m = l-1;m>=0;m--)
        {
            n.append(s.substr(m,1));
        }
        return n;
        
    }
};


344. Reverse String