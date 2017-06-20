224. Basic Calculator
//正确的解法，被虐了，很难受
//一个存放操作数，每次进栈要注意，如果操作符栈顶元素为'+'/'-'，则需要立即计算。

//一个存放操作符（包括括号），每次出现')'时，不断进行出栈计算再进栈，直到弹出'('，说明当前括号内计算完毕。


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
            if(s[index] == '(' || s[index] == '+' || s[index] == '-')
            {
                op.push(s[index++]);
            }
            else if(int(s[index]) >= 48 && int(s[index]) <= 57)
            {
                int n = 0;
                while(index < s.size() && int(s[index]) >= 48 && int(s[index]) <= 57)
                {
                    n = n * 10 + int(s[index] - '0');
                    ++index;
                }
                num.push(n);
                
                while(!op.empty() && op.top() != '(')
                {
                    int nm1 = num.top();
                    num.pop();
                    int nm2 = num.top();
                    num.pop();
                    if(op.top() == '+')
                    {
                        nm1 = nm1 + nm2;
                        num.push(nm1);
                    }
                    else
                    {
                        nm1 = nm2 - nm1;
                        num.push(nm1);
                    }
                    op.pop();
                }
            }
            else
            {
                while(op.top() != '(')
                {
                    int nm1 = num.top();
                    num.pop();
                    int nm2 = num.top();
                    num.pop();
                    if(op.top() == '+')
                    {
                        nm1 = nm1 + nm2;
                        num.push(nm1);
                    }
                    else
                    {
                        nm1 = nm2 - nm1;
                        num.push(nm1);
                    }
                    op.pop();
                }
                op.pop();
                while(!op.empty() && op.top() != '(')
                {
                    int nm1 = num.top();
                    num.pop();
                    int nm2 = num.top();
                    num.pop();
                    if(op.top() == '+')
                    {
                        nm1 = nm1 + nm2;
                        num.push(nm1);
                    }
                    else
                    {
                        nm1 = nm2 - nm1;
                        num.push(nm1);
                    }
                    op.pop();
                }
                ++index;
            }
        }
        return num.top();
    }
};