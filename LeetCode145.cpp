55. Jump Game
//DP，状态值的意思是能否到达这个节点
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool canbehere[nums.size()];
        canbehere[0] = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            canbehere[i] = 0;
            for(int j = 0; j < i; ++j)
            {
                if(canbehere[j] && (j + nums[j] >= i) )
                {
                    canbehere[i] = 1;
                    break;
                }
            }
        }
        return canbehere[nums.size() - 1];
    }
};