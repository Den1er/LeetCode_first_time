500. Keyboard Row
//自己写的丑陋代码，好丑
class Solution {
public:
    string s1 = "qwertyuiop";
    string s2 = "asdfghjkl";
    string s3 = "zxcvbnm";
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for(int i = 0; i < words.size(); ++i)
        {
            if(StrInStr(words[i]))
                result.push_back(words[i]);
        }
        return result;
    }
    bool ChInStr(char input, string str)
    {
        //if(str.size() == 0) return 0;
        for(int i = 0;i < str.size(); ++i)
        {
            if(tolower(input) == str[i])
                return 1;
        }
        return 0;
    }
    bool StrInStr(string str_input)
    {
        if(str_input.size() == 1 || str_input.size() == 0)
            return 1;
        int before = 0, after = 0;
        int i = 0;
        while(i < str_input.size())
        {
            if(i == 0)
            {
                if(ChInStr(str_input[i], s1))
                    after = 1;
                else if(ChInStr(str_input[i], s2))
                    after = 2;
                else
                    after = 3;
            }
            else
            {
                before = after;
                if(ChInStr(str_input[i], s1))
                    after = 1;
                else if(ChInStr(str_input[i], s2))
                    after = 2;
                else
                    after = 3;
                if(before != after)
                    return 0;
            }
            ++i;
        }
        return 1;
    }
};

//简便操作

vector<string> findWords(vector<string>& words) {
    unordered_set<char> row1 {'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'};
    unordered_set<char> row2 {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> row3 {'z', 'x', 'c', 'v', 'b' ,'n', 'm'};
    vector<unordered_set<char>> rows {row1, row2, row3};
    
    vector<string> res;
    for(string& word : words){
        int row = -1;
        for(int i=0; i<3; i++)
            if(rows[i].count(tolower(word[0])) > 0)
                row = i;
        
        if (row==-1) continue;
        
        bool valid = true;
        for(int j=1,sz=word.size();j<sz;j++){
            if(rows[row].count(tolower(word[j])) == 0){
                valid = false;
                break;
            }
        }
        if (valid) res.push_back(word);
    }
    return res;
}