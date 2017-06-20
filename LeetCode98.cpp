17. Letter Combinations of a Phone Number
//本题较简单
class Solution {
public:
    vector<char> vec_2 = {'a', 'b', 'c'};
    vector<char> vec_3 = {'d', 'e', 'f'};
    vector<char> vec_4 = {'g', 'h', 'i'};
    vector<char> vec_5 = {'j', 'k', 'l'};
    vector<char> vec_6 = {'m', 'n', 'o'};
    vector<char> vec_7 = {'p', 'q', 'r', 's'};
    vector<char> vec_8 = {'t', 'u', 'v'};
    vector<char> vec_9 = {'w', 'x', 'y', 'z'};
    vector<vector<char>> vec = {vec_2, vec_3, vec_4, vec_5, vec_6, vec_7, vec_8, vec_9};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0)
            return result;
        string s;
        dfs(digits, 0, result, s);
        return result;
    }
    void dfs(string digits, int begin, vector<string>& result, string& s)
    {
        if(begin == digits.size())
        {
            result.push_back(s);
        }
        else
        {
            
            int n = int(digits[begin] - '2');
            for(int j = 0; j < vec[n].size(); ++j)
            {
                s += vec[n][j];
                dfs(digits, begin + 1, result, s);
                s = s.substr(0, s.size() - 1);
            }
            
        }
    }
};