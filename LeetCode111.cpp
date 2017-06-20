125. Valid Palindrome
//一发入魂
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 1 || s.empty())        
        {
            return 1;
        }
        int low = 0;
        int high = s.size() - 1;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        while(low < high)
        {
            if(s[low] == s[high] && isalnum(s[low]) && isalnum(s[high]))
            {
                ++low;
                --high;
            }
            else if(!isalnum(s[low]))
            {
                ++low;
            }
            else if(!isalnum(s[high]))
            {
                --high;
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};

