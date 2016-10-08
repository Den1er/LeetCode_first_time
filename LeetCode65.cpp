26. Remove Duplicates from Sorted Array
class Solution {
public:
        int removeDuplicates(vector<int>& nums) {
                   int s = 1;
                   int count = 0;
                   int oldlen = nums.size();
                   for(int i = 1; i<nums.size(); ++i)
                   {
                       if(nums[i]!=nums[i-1])
                       {
                           nums[s++] = nums[i];
                       }
                       else
                       {
                           count++;
                       }
                   }
                   nums.resize(oldlen-count);
                   return nums.size();
                }
};
