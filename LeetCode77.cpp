class Solution {
public:
        int romanToInt(string s) {
                    int i = 0;
                    for(int j = s.size()-1; j>-1; --j)
                    {
                        char c = s[j];
                        switch(c):
                        {
                        case 'I':
                            i+=(i>=5?-1:1);
                            break;
                        case 'V':
                            i+=5;
                            break;
                        case 'X':
                            i += 10*(i>=50?-1:1);
                            break;
                        case 'L':
                            i += 50;
                            break;
                        case 'C':
                            i += 100*(i>=500?-1:1);
                            break;
                        case 'D':
                            i += 500;
                            break;
                        case 'M':
                            i += 1000;
                            break;
                        }
                    }
                    return i;
                }
};
