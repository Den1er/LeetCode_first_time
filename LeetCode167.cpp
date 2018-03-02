537. Complex Number Multiplication
//简单思路
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int tag1, tag2;
        tag1 = a.find('+');
        tag2 = b.find('+');

        int ar = digitalProcess(a.substr(0, tag1));
        int ai = digitalProcess(a.substr(tag1 + 1, a.size() - tag1 - 2));
        int br = digitalProcess(b.substr(0, tag2));
        int bi = digitalProcess(b.substr(tag2 + 1, b.size() - tag2 - 2));

        int rr = ar * br - ai * bi;
        int ri = ar * bi + ai * br;
        return int2str(rr) + '+' + int2str(ri) + 'i';

    }
    int digitalProcess(string input)
    {
        bool flag = 0;
        if(input[0] == '-')
            flag = 1;

        return flag == 1 ? (-1 * stoi(input.substr(1, input.size() - 1))) : stoi(input);
    }
    string int2str(const int input)
    {
        stringstream stream;
        stream << input;
        return stream.str();
    }
};
