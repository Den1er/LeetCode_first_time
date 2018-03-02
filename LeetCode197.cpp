464. Can I Win
//很难的一道题
//本题是一道博弈论的题，使用记忆化搜索
//考虑到敌我双方都是相同的实力，每个人的不同仅仅是先选或者后选的不同
//可以举一个例子,max = 3, target = 4，画出搜索树，会发现由于双方实力相同，之前的状态仅仅需要记录选过哪些元素
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        //
        int addItem = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if(addItem < desiredTotal)  return false;
        if(desiredTotal <= 0)    return true;
        m_final = vector<char>(1 << maxChoosableInteger, 0);
        return canIWin(maxChoosableInteger, desiredTotal, 0);
    }
    bool canIWin(int max, int now, int state)
    {
        if(now <= 0)    return false;
        if(m_final[state] != 0) return m_final[state] == 1;
        for(int i = 0; i < max; ++i)
        {
            if(state & (1 << i))   continue;
            if(canIWin(max, now - i - 1, state | (1 << i)) == false)
                return true;
        }
        m_final[state] = -1;
        return false;
    }
private:
    vector<char> m_final;
};

