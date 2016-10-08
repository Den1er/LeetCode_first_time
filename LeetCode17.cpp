class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_res = 0;
        for(int n = 0;n<nums.size();n++)
        {
            xor_res ^=nums[n];
        }
        //xor_res &= (-xor_res);
        int bit = 0;
        for(bit;bit<32;bit++)
        {
            if((xor_res>>bit) & 1==1)
                break;
        }
        int result1 = 0,result2 = 0;
        for(int n = 0;n<nums.size();n++)
        {
            if((nums[n]>>bit)&1 == 1)
            {
                result1 ^= nums[n];
            }
            else
            {
                result2 ^= nums[n];
            }
        }
        //result2 = xor_res ^ result1;
        vector<int> result;
        result.push_back(result1);
        result.push_back(result2);
        return result;
    }
};


260. Single Number III