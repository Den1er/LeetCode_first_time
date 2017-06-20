22.Generate Parentheses
//1. 只要"("的数量没有超过n，都可以插入"("。
//2. 而可以插入")"的前提则是当前的"("数量必须要多余当前的")"数量。
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)
        {
            return res;
        }
        string tmp;
        dfs(n, 0, 0, res, tmp);
        return res;
    }
    void dfs(int n, int left, int right, vector<string>& res, string& tmp)
    {
        if(left == n && right == n)
        {
            res.push_back(tmp);
            return;
        }
        else if(left < n)
        {
            dfs(n, left + 1, right, res, tmp + "(");
        }
        if(left > right)
        {
            dfs(n, left, right + 1, res, tmp + ")");
        }

    }
};
