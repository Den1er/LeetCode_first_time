128. Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> memory;
        for(int i = 0; i < nums.size(); ++i)
        {
            memory[nums[i]] = 1;
        }
        int res = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(memory[nums[i]])
            {
                int len = 1;
                int left = nums[i] - 1;
                int right = nums[i] + 1;
                
                while(memory[left] == 1)
                {
                    ++len;
                    memory[left--] = 0;
                }
                while(memory[right] == 1)
                {
                    ++len;
                    memory[right++] = 0;
                }
                if(len > res)
                    res = len;
            }
            
        }
        return res;
    }
};