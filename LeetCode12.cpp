338. Counting Bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        for(int i = 1;i<num+1;i++)
        {
            res[i] = res[i>>1]+(i&1);
            res.push_back(res[i]);
        }
        return res;
    }
};


class Solution {
public:
    bool canWinNim(int n) {
        if(n<=3)return true;
        for(int i=1;i<=3;i++){
            if(!canWinNim(n-i))return true;
        }
        return false;
    }
};