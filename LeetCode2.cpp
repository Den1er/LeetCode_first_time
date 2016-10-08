class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        int final;
        if(length==0)
            final = 0;
        else if(length==1)
            final = 1;
        else
        {
            final = 1;
            for(int i = 1;i<length;i++)
            {
        	    if(nums[final-1]!=nums[i])
        		    {
        		    nums[final]=nums[i];
        		    final++;
        		    }
            }
        }
        return final;
    }
};