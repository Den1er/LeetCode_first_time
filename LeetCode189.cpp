724. Find Pivot Index
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0)    return -1;

        int n = nums.size();
        int sum = 0;
        //vector<int> left(n , 0);
        //vector<int> right(n , 0);
        int left, right;

        for(int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        left = 0;
        right = sum - nums[0];
        if(left == right) return 0;
        
        for(int i = 1; i < nums.size(); ++i)
        {
            left = left + nums[i - 1];
            right = right - nums[i];
            //cout << left[i] << right[i] << endl;
            if(left == right) 
            {
                return i;
            }
        }
        return -1;
    }
};
