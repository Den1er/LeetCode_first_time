22. Generate Parentheses
//这个方法是递归的方法，可惜是错的，并没有考虑到另外一种情况，导致解不足，正确的答案确实没有想出来
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)
        {
            return res;
        }
        return dfs(n);
    }
    vector<string> dfs(int n )
    {
        if(n == 1)
        {
            string s = "()";
            vector<string> res;
            res.push_back(s);
            return res;
        }
        else
        {
           vector<string> res;
           vector<string> last = dfs(n - 1);
           //hash_map<string, bool> map;
           for(int i = 0; i < last.size(); ++i)
           {
               string s = "(" + last[i] + ")";
               vector<string>::iterator it;
               it = find(res.begin(), res.end(), s);
               if(it == res.end())
               {
                   res.push_back(s);
               }

               s = "()" + last[i];
               it = find(res.begin(), res.end(), s);
               if(it == res.end())
               {
                   res.push_back(s);
               }
               
               s = last[i] + "()";
               it = find(res.begin(), res.end(), s);
               if(it == res.end())
               {
                   res.push_back(s);
               }
           }
           return res;

        }
    }
};
