27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        sort(nums.begin(),nums.end());
        int count = 0;
        int first = -1;
        for(int i = 0; i<nums.size(); ++i)
        {
            if(nums[i]==val)
            {
                ++count;
                if(first==-1)
                {
                    first = i;
                }
            }
        }
        int oldlen = nums.size();
        for(int i = first+count; i<nums.size(); ++i)
        {
            nums[i-count] = nums[i];
        }
        nums.resize(nums.size()-count);
        return oldlen-count;
    }
};




class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s = 0;
        // 依次判断每个数是否等于val，将不等于的那些组成新数组
        for (int i = 0; i < nums.size(); i++) if (nums[i] != val) {
            // 等号右侧相当于原本数组中的数，等号左边相当于删除后新数组的数
            nums[s ++] = nums[i];
        }
        // 返回新长度
        return s;
    }
};