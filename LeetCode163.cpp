657. Judge Route Circle
//无脑
class Solution {
public:
        bool judgeCircle(string moves) {
             if(moves.empty())  return 0;
             int horizon = 0;
             int vertical = 0;
             for(int i = 0; i < moves.size(); ++i)
             {
                 if(moves[i] == 'U')    ++vertical;
                 if(moves[i] == 'D')    --vertical;
                 if(moves[i] == 'L')    ++horizon;
                 if(moves[i] == 'R')    --horizon;
             }
             if(vertical == 0 && horizon == 0)
                 return 1;
             return 0;
        }
};
