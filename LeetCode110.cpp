60. Permutation Sequence
//几乎是抄了别人的，有细节没仔细考虑，笔和纸很重要
class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> num(n + 1, 1);
        for(int i = 1; i < n; ++i)
        {
            num[i] = num[i - 1] * i;
        }
        vector<char> digits = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int i = n - 1;
        while(i)
        {
            int res = (k - 1) / num[i];
            k = k - res * num[i];
            result.push_back(digits[res]);
            digits.erase(digits.begin() + res);
            --i;
            
        }
        result.push_back(digits[k - 1]);
        return result;
    }
};