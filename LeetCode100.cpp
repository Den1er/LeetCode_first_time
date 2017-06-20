class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if(n == 0)
        {
            result.push_back(0);
            return result;
        }
        vector<string> res = dfs(n);
        translate(result, res);
        return result;
    }
    vector<string> dfs(int n)
    {
        if(n == 1)
        {
            vector<string> res = {"0", "1"};
            return res;
        }
        else
        {
            vector<string> last = dfs(n - 1);
            vector<string> result;
            for(int i = 0; i < last.size(); ++i)
            {
                string tmp = "0" + last[i];
                result.push_back(tmp);
            }
            for(int i = last.size() - 1;i >= 0; --i)
            {
                string tmp = "1" + last[i];
                result.push_back(tmp);
            }
            return result;
        }
    }
    void translate(vector<int>& result, vector<string>& res)
    {
        for(int i = 0; i < res.size(); ++i)
        {
            int r = 0;
            int length = res[i].length();
            for(int j = length - 1 ; j >= 0; --j)
            {
                if(res[i][length - 1 - j] == '1')
                r += pow(2, j);
            }
            result.push_back(r);
        }
    }
};
