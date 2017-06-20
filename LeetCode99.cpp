88. Merge Sorted Array
//从数组的后面放入元素
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int last = m + n - 1;
        while(i >= 0 || j >= 0)
        {
            if(i >= 0 && j >= 0)
            {
                nums1[last--] = max(nums1[i], nums2[j]);
                if(nums1[i] > nums2[j])
                {
                    --i;
                }
                else
                {
                    --j;
                }
            }
            else if(i >= 0 && j < 0)
            {
                nums1[last--] = nums1[i--];
            }
            else
            {
                nums1[last--] = nums2[j--];
            }
        }
    }
};