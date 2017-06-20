91. Decode Ways
//这道题写了好久好久，先是逻辑上出现了漏洞，状态方程f[i] += f[i - 1]//自己合法的时候
//f[i] += f[i - 2]//自己与前一个元素组成的数字合法的时候
class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0)
            return 0;
        if(s[0] == '0')
            return 0;
        int len = s.length();
        int NumofWay[len];
        
        NumofWay[0] = 1;
        if(s.size() >= 2)
        {
            if(int(s[0] - 48) * 10 + int(s[1] - 48) <= 26)
            {
                if(s[1] != '0')
                    NumofWay[1] = 2;
                else
                    NumofWay[1] = 1;
            }
            else
            {
                if(s[1] == '0')
                    return 0;
                else
                    NumofWay[1] = 1;
            }
        }
        for(int i = 2; i < s.size(); ++i)
        {
            NumofWay[i] = 0;
            for(int j = 1; j <= 2 && i - j >= 0; ++j)
            {
                int flag = 0;
                if(j == 1)
                {
                    if(s[i] != '0')
                    {
                        NumofWay[i] += NumofWay[i - j];
                    }
                    else
                    {
                        flag = 1;
                    }
                }
                else
                {
                    if(flag == 1)
                    {
                        if(s[i - 1] == '1' || s[i - 1] == '2')
                        {
                            NumofWay[i] += NumofWay[i - j];
                        }
                        else
                            return 0;
                    }
                    else
                    {
                        if(s[i - 1] != '0')
                        {
                            int dig = int(s[i - 1] - 48) * 10 + int(s[i] - 48);
                            if(dig <= 26)
                                NumofWay[i] += NumofWay[i - j];
                        }
                    }
                }
            }
            
        }
        
        for(int i = 0; i < s.length(); ++i)
        {
            cout<<NumofWay[i]<<endl;
        }
        
        return NumofWay[s.length() - 1];
    }
};


//网上的很冷酷的代码，很帅，原理也是先把前两项计算出来
class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        if (s.size() == 0)
            return 0;
        else if (s.size() == 1)
            return s[0] != '0' ? 1 : 0;
        
        int* dp = new int[s.size()];
        dp[0] = s[0] != '0' ? 1 : 0;
        dp[1] = (s[0] != '0' && s[1] != '0'? 1 : 0) +
        ((s[0] != '0' && (toInt(s[0]) * 10 + toInt(s[1])) <= 26) ? 1 : 0);
        
        for (int i = 2; i < s.size(); ++i) {
            dp[i] = 0;
            if(s[i] != '0')
                dp[i] += dp[i-1];
            if(s[i-1] != '0' && (toInt(s[i-1]) * 10 + toInt(s[i])) <= 26){
                dp[i] += dp[i-2];
            }
        }
        
        return dp[s.size() - 1];
    }
    
    int toInt(char c){
        return c - '0';
    }
};