67. Add Binary
//自己写的很笨的方法
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty())   return b;
        if(b.empty())   return a;
        int a_length = a.length() - 1;
        int b_length = b.length() - 1;
        string result;
        bool flag = 0;
        while(a_length >= 0 || b_length >= 0 || flag == 1)
        {
            if(a_length >=0 && b_length >= 0)
            {
                if(int(a[a_length] - '0') + int(b[b_length] - '0') + flag == 3)
                {
                    flag = 1;
                    result += "1";
                    --a_length;
                    --b_length;
                }
                else if (int(a[a_length] - '0') + int(b[b_length] - '0') + flag == 2)
                {
                    flag = 1;
                    result += "0";
                    --a_length;
                    --b_length;
                }
                else if (int(a[a_length] - '0') + int(b[b_length] - '0') + flag == 1)
                {
                    flag = 0;
                    result += "1";
                    --a_length;
                    --b_length;
                }
                else
                {
                    flag = 0;
                    result += "0";
                    --a_length;
                    --b_length;
                }
            }
            else if (a_length >= 0 && b_length < 0)
            {
                if(int(a[a_length] - '0') + flag == 2)
                {
                    flag = 1;
                    result += "0";
                    --a_length;
                }
                else if(int(a[a_length] - '0') + flag == 1)
                {
                    flag = 0;
                    result += "1";
                    --a_length;
                }
                else
                {
                    flag = 0;
                    result += "0";
                    --a_length;
                }
            }
            else if (b_length >= 0 && a_length < 0)
            {
                if(int(b[b_length] - '0') + flag == 2)
                {
                    flag = 1;
                    result += "0";
                    --b_length;
                }
                else if(int(b[b_length] - '0') + flag == 1)
                {
                    flag = 0;
                    result += "1";
                    --b_length;
                }
                else
                {
                    flag = 0;
                    result += "0";
                    --b_length;
                }
            }
            else
            {
                result += "1";
                flag = 0;
            }
        }
        string s(result.rbegin(),result.rend());
        return s;
    }
};