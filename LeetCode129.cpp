43. Multiply Strings

//自己的丑陋方法，注意点是0以及Int和char之间的转换
class Solution {
public:
    string multiply(string num1, string num2) {
        string s1(num1.rbegin(),num1.rend());
        string s2(num2.rbegin(),num2.rend());
        string s;
        if(num1.empty() || num2.empty())    return s;
        if(s1 == "0" || s2 == "0")  return "0";
        int size1 = s1.size();
        int size2 = s2.size();
        string res(size1 + size2, '0');
        for(int i = 0; i < size1; ++i)
        {
            for(int j = 0; j < size2; ++j)
            {
                int mul1 = int(s1[i] - '0');
                int mul2 = int(s2[j] - '0');
                int tmp = mul1 * mul2;
                if(tmp < 10)
                {
                    int k = i + j;
                    while(tmp + int(res[k] - '0') > 9)
                    {
                        int add = tmp + int(res[k] - '0');
                        res[k++] = add % 10 + '0';
                        tmp = add / 10;
                    }
                    res[k] = tmp + res[k];
                }
                else
                {
                    int k = i + j;
                    int tmp1 = tmp % 10;
                    while(tmp1 + int(res[k] - '0') > 9)
                    {
                        int add = tmp1 + int(res[k] - '0');
                        res[k++] = add % 10 + '0';
                        tmp1 = add / 10 ;
                    }
                    res[k] = tmp1 + res[k];
                    
                    k = i + j + 1;
                    int tmp2 = tmp / 10;
                    while(tmp2 + int(res[k] - '0') > 9)
                    {
                        int add = tmp2 + int(res[k] - '0');
                        res[k++] = add % 10 + '0';
                        tmp2 = add / 10 ;
                    }
                    res[k] = tmp2 + res[k];
                }
            }
        }
        if(res[size1 + size2 - 1] == '0')
            res = res.substr(0,res.size() - 1);
        string result(res.rbegin(),res.rend());
        return result;
    }
};