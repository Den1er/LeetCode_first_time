217. Contains Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> asd;
        for(int i = 0; i<nums.size(); ++i)
        {
            if(asd.find(nums[i])==asd.end())
            {
                asd[nums[i]] = 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};