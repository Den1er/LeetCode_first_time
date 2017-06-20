521. Longest Uncommon Subsequence I
//嗯。。估计面试不会出这个
class Solution {
public:
    int findLUSlength(string a, string b) {
        int s_a = a.size();
        int b_a = b.size();
        if(s_a != b_a)
            return s_a > b_a ? s_a : b_a;
        if(a == b)
            return -1;
        else
            return s_a;
    }
};
