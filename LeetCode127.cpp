520. Detect Capital
//本题较简单
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 0 || word.size() == 1)
            return true;
        //前两个元素的判断
        bool b1 = isCapital(word[0]);
        bool b2 = isCapital(word[1]);
        if(b1 == 0 && b2 == 1)
            return false;
        int i = 2;
        for(;i < word.size(); ++i)
        {
            if(isCapital(word[i]) != b2)
                return false;
            b2 = isCapital(word[i]);
        }
        return true;
    }
    bool isCapital(char c)
    {
        if(c >= 'a' && c <= 'z')
            return 0;
        return 1;
    }
};
