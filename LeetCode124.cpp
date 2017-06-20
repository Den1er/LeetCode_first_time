227. Basic Calculator II
//大概的注释都在代码中
class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        string::iterator end_pos = std::remove(s.begin(),s.end(),' ');
        s.erase(end_pos, s.end());
        int index = 0;
        
        while(index < s.size())
        {
            if(s[index] == '*' || s[index] == '/')
            {
                op.push(s[index++]);
            }
            else if(s[index] == '+' || s[index] == '-')   //如果栈中存在着+或者-，那么先将其计算出来，
            {
                if(op.empty())
                {
                    op.push(s[index++]);
                }
                else
                {
                    if(num.size()  == 1)  //例如-2+1
                    {
                        int num2 = num.top();
                        num.pop();
                        if(op.top() == '+')
                            num.push(num2);
                        else
                            num.push(-num2);
                    }
                    else
                    {
                        int num1 = num.top();
                        num.pop();
                        int num2 = num.top();
                        num.pop();
                        if(op.top() == '+')
                        {
                            num.push(num1 + num2);
                        }
                        else
                        {
                            num.push(num2 - num1);
                        }
                    }
                    op.pop();
                    op.push(s[index]);
                    ++index;
                }
            }
            else    //数字，先完整获取一个数字，再根据op栈中的符号，如果是*或/就立马进行运算，如果是+或-，就放如数字栈中
            {
                int n = 0;
                while(index < s.size() && int(s[index]) >= 48 && int(s[index]) <= 57)
                {
                    n = n * 10 + int(s[index] - '0');
                    ++index;
                }
                num.push(n);
                while(!op.empty() && (op.top() == '*' || op.top() == '/'))
                {
                    int num1 = num.top();
                    num.pop();
                    int num2 = num.top();
                    num.pop();
                    if(op.top() == '*')
                    {
                        num.push(num1 * num2);
                    }
                    else
                    {
                        num.push(num2/ num1);
                    }
                    op.pop();
                }
            }
        }
        if(num.size() == 2)  //如果到最后一步，需要完成最后的计算
            
        {
            int res = num.top();
            num.pop();
            if(op.top() == '+')
                res += num.top();
            else
                res =  num.top() - res;
            return res;
        }
        else
            return num.top();
    }
};



更好的答案

class Solution {
public:
    int calculate(string s) {
        int res = 0, d = 0;
        char sign = '+';
        stack<int> nums;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0') {
                d = d * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == s.size() - 1) {
                if (sign == '+') nums.push(d);
                if (sign == '-') nums.push(-d);
                if (sign == '*' || sign == '/') {
                    int tmp = sign == '*' ? nums.top() * d : nums.top() / d;
                    nums.pop();
                    nums.push(tmp);
                }
                sign = s[i];
                d = 0;
            }
        }
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};