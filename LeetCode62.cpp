169. Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        unordered_map<int,int>   res;
        unsigned int valve = nums.size()/2+1;
        for(int i = 0; i<nums.size(); ++i)
        {
            auto iter = res.find(nums[i]);
            if(iter!=res.end())
            {
                ++res[nums[i]];
                if(res[nums[i]]==valve)
                    return nums[i];
            }
            else
            {
                res[nums[i]] = 1;
                
            }
        }
        return 0;
    }
};