class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int,int> hash;
        for(int i = 0;i<nums1.size();i++)
        {
            hash[nums1[i]] = 1;
        }
        for(int i = 0;i<nums2.size();i++)
        {
            if(hash[nums2[i]] == 1)
            {
                result.push_back(nums2[i]);
                hash.erase(nums2[i]);
            }
        }
        return result;
    }
};

349. Intersection of Two Arrays