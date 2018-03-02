179. Largest Number
//使用已有的stl sort函数，我们只需要提供一个比较函数用以告诉排序算法。
//边界条件是全0的以及0打头的字符串
class Solution {
public:
    string largestNumber(vector<int>& nums) {
       vector<string> res;
       int len = nums.size();
       for(int i = 0; i < len; ++i)
       {
           res.push_back(to_string(nums[i]));
       }
       sort(res.begin(), res.end(), cmp);

       string result = "";
       for(auto str : res)  result += str;

       int i = 0;
       while(result[i] == '0')  ++i;
       if(i == res.size())  return "0";
       return result.substr(i);
    }
    static bool cmp(string& s1, string& s2)
    {
        return (s1 + s2) > (s2 + s1);
    }
};
