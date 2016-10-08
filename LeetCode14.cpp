167. Two Sum II - Input array is sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> two;
        int left = 0;
        int right = numbers.size()-1;
        while(left<right)
        {
            int temp = numbers[left]+numbers[right];
            if(temp == target)
            {
                two.push_back(left+1);
                two.push_back(right+1);
                return two;
            }
            else if (temp<target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return two;
    }
};