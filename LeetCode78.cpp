345. Reverse Vowels of a String
class Solution {
public:
    string reverseVowels(string s) {
        if(s.size()==0||s.size()==1)    return s;
        int left,right;
        left = 0;
        right = s.size()-1;
        while(left<right)
        {
            if(isVowel(s[left])&&isVowel(s[right]))
            {
                if(s[left]!=s[right])
                {
                    char tmp = s[left];
                    s[left] = s[right];
                    s[right] = tmp;
                }
                ++left;
                --right;
            }
            else if(!isVowel(s[left])&&isVowel(s[right]))
            {
                ++left;
            }
            else if(!isVowel(s[right])&&isVowel(s[left]))
            {
                --right;
            }
            else
            {
                ++left;
                --right;
            }
        }
        return s;
    }
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        || (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') ;
    }
};