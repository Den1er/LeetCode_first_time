39. Combination Sum
//没看任何答案写的，三个小时，记录一下思路
//先试着用递归非引用的方法，发现了问题，该题涉及到两次出栈，递归非引用适用于一次出栈
//因此，试着写递归引用的方法，之所以这么耗时间，主要问题是有些条件没总结出来

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<int> temp;
         vector<vector<int>> result;
         sort(candidates.begin(),candidates.end());
         int sum = 0;
         helper(0, candidates, temp, result, sum, target);

         return result;
    }

    void helper(int bot, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& res, int& sum, int target)
    {
        int len = candidates.size();
        for(; bot < len; ++bot)
        {
            //int n = candidates[bot];
            if(sum + candidates[bot] == target)
            {
                temp.push_back(candidates[bot]);
                res.push_back(temp);
                if(temp.size() > 1)             //分两种情况考虑，若第一层就直接满足条件，则直接跳出循环，但是还存在temp中还存在需要两次出栈的情况
                {
                    temp.pop_back();
                    sum -= temp[temp.size()-1];
                    temp.pop_back();
                }
                break;
            }
            else if(sum + candidates[bot] < target)
            {
                sum += candidates[bot];
                temp.push_back(candidates[bot]);
                helper(bot, candidates, temp, res, sum, target);
            }
            else
            {
                //cout<<candidates[bot];
                if(temp.size() > 0)//若栈顶只有一层，直接break，存在两层的需要break掉当前层，并且使上一层接着下一个循环
                {
                    sum -= temp[temp.size()-1];
                    temp.pop_back();
                }
                break;
            }
            if(bot == len - 1)//在循环到最后一个元素还未满足条件时，必须清空该层元素（原理类似于系统自动出栈，由于我是手动管理sum与temp，这一步需要我自己来做）
            {
                if(temp.size() > 0)
                {
                    sum -= temp[temp.size() -1 ];
                    temp.pop_back();
                }
            }
        }
    }
    
};
