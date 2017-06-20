241. Different Ways to Add Parentheses
//思路完全是照抄网上的，我是没想出来这个解法，不过这个问题不是生硬的加上括号就能解决的，而是需要转换思考，换个思路再做
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return dfs(input);
    }
    
    vector<int> dfs(string s)
    {
        vector<int> index;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '*' || s[i] == '+' || s[i] == '-')
            {
                index.push_back(i);
            }
        }
        
        vector<int> res;
        
        if(index.size() == 0)
        {
            int num = atoi(s.c_str());
            res.push_back(num);
            return res;
        }
        
        for(int i = 0; i < index.size(); ++i)
        {
            char op = s[index[i]];
            vector<int> a = dfs(s.substr(0, index[i]));
            vector<int> b = dfs(s.substr(index[i] + 1));
            //cout<<s.substr(0, index[i])<<endl;
            //cout<<s.substr(index[i] + 1)<<endl;
            for(int i1 = 0; i1 < a.size(); ++i1)
            {
                for(int i2 = 0; i2 < b.size(); ++i2)
                {
                    //cout<<"for"<<a[i1]<<'\t'<<op<<'\t'<<b[i2]<<endl;
                    if(op == '*')
                        res.push_back(a[i1] * b[i2]);
                    if(op == '+')
                        res.push_back(a[i1] + b[i2]);
                    if(op == '-')
                        res.push_back(a[i1] - b[i2]);
                }
            }
        }
        return res;
    }
};