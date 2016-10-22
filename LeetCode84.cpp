189. Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> left,right;
        for(int i = n-k;i<n;i++)
        {
            left.push_back(nums[i]);
        }
        for(int i = 0;i<n-k;i++)
        {
            right.push_back(nums[i]);
        }
        nums.clear();
        for(int i = 0;i<k;i++)
        {
            nums.push_back(left[i]);
        }
        for(int i = 0;i<n-k;i++)
        {
            nums.push_back(right[i]);
        }
    }
};

神奇的算法
public class Solution {
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++; end--;
        }
    }
    public void rotate(int[] nums, int k) {
        if (nums.length == 0) {
            return;
        }
        
        k = k % nums.length;
        reverse(nums, 0, nums.length - k - 1);
        reverse(nums, nums.length - k, nums.length - 1);
        reverse(nums, 0, nums.length - 1);
    }
}