347. Top K Frequent Elements
//寻找数组中的前K个元素，采用了桶排序的算法。
//桶的编号作为元素的出现次数，则一共需要N + 1个桶。
//本题也可使用C++中的priority_queue，自动帮助排序，提取前K个元素即可
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> reg;
        for(auto word : nums)   reg[word]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto it : reg)  bucket[it.second].push_back(it.first);

        vector<int> result;
        
        for(int i = bucket.size() - 1; i >= 0; --i)
        {
            for(int j = 0; j < bucket[i].size(); ++j)
            {
                if(result.size() < k)
                    result.push_back(bucket[i][j]);
                if(result.size() == k)
                    return result;
            }
        }
        return result;
    }
};
