401. Binary Watch
//也是自己写的，效率很低，有一个函数叫做to_string，很好用
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> rep = {1, 2, 4, 8, 101, 102, 104, 108, 116, 132};
        vector<string> res;
        vector<int> tmp;
        dfs(num, 0, res, tmp,rep);
        return res;
    }
    void dfs(int num, int begin, vector<string>& res, vector<int> tmp, vector<int>& rep)
    {
        if(num == 0)
        {
            string s = helper(tmp, rep);
            if(!s.empty())
            {
                res.push_back(s);
            }
            return;
        }
        for(int i = begin; i + num < 11; ++i)
        {
            tmp.push_back(i);
            dfs(num - 1, i + 1, res, tmp, rep);
            tmp.pop_back();
        }
    }
    string helper(vector<int> tmp, vector<int>& rep)
    {
        int hour = 0;
        int minute = 0;
        for(int i = 0 ; i < tmp.size(); ++i)
        {
            if(rep[tmp[i]] < 100)
            {
                hour += rep[tmp[i]];
            }
            else
            {
                minute += (rep[tmp[i]] - 100);
            }
        }
        string res;
        if(hour > 11 || minute > 59)
        {
            return res;
        }
        stringstream ss;
        ss<<hour;
        res += ss.str();
        res += ":";
        if(minute < 10)
        {
            res += "0";
            stringstream s;
            s<<minute;
            res += s.str();
        }
        else
        {
            stringstream s;
            s<<minute;
            res += s.str();
        }
        return res;
    }
};