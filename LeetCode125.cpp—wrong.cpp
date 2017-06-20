224. Basic Calculator
//自己想的方法，有问题，还是应该把括号放入栈里，否则很麻烦
class Solution {
public:
    int calculate(string s) {
        stack<int> numberstack;
        stack<char> symbol;       
        int index = 0;
        int num = 0;
        while(index < s.size() || numberstack.size() != 1)
        {
            if(index < s.size())
            {
                if(s[index] == '(' || s[index] == ')')
                    ++index;
                else if(int(s[index]) <=57 && int(s[index] >= 48))   //遇上数字，则将后续的数字全部存储在栈中
                {
                    while(index < s.size() && int(s[index]) <=57 && int(s[index] >= 48))
                    {
                        num = num * 10 + int(s[index] - '0');
                        ++index;
                    }
                    numberstack.push(num);
                    num = 0;
                }
                else if(s[index] == '+' || s[index] == '-')   //两种情况，一个是后有括号，让符号入栈，后无括号，则直接计算
                {
                    if(s[index + 1] == '(')
                    {
                        symbol.push(s[index]);
                        ++index;
                    }
                    else   //将+ -号后的所有数字收集，并且进行运算
                    {
                        char sign = s[index];
                        while(index < s.size() && int(s[index]) <=57 && int(s[index] >= 48))
                        {
                            num = num * 10 + int(s[index] - '0');
                            ++index;
                        }
                        if(sign == '+')
                        {
                            int add = numberstack.top();
                            numberstack.pop();
                            num += add;
                            numberstack.push(num);
                        }
                        else
                        {
                            int red = numberstack.top();
                            numberstack.pop();
                            num = red - num;
                            numberstack.push(num);
                        }
                            num = 0;
                    }
                }
        }
        else
        {
            if(symbol.top() == '+')      //计算到字符串计算结束之后，讲栈中剩下的东西计算出来
                {
                    int add2 = numberstack.top();
                    numberstack.pop();
                    int add1 = numberstack.top();
                    numberstack.pop();
                    numberstack.push(add1 + add2);
                    symbol.pop();
                }
                else
                {
                    int minus2 = numberstack.top();
                    numberstack.pop();
                    int minus1 = numberstack.top();
                    numberstack.pop();
                    numberstack.push(minus1 - minus2);
                    symbol.pop();
                }
        }

    }
        return numberstack.top();
    }
};
