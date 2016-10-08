#include "iostream"

// Leetcode1 2SUM
class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) 
    {
    	vector number = num;
    	std::sort(number.begin(),num.end());

    	int length = number.size();
    	int left = 0;
    	int right = length-1;
    	int sum = 0;

    	vector index;

    	while(left<right)
    	{
    		sum = number[left]+number[right];

    		if(sum==target)
    		{
    			for(int i = 0;i<length;i++)
    			{
    				if(num[i]==number[left])
    				{
    					index.push_back(i+1);
    				}
    				else if(num[i]==number[right])
    				{
    					index.push_back(i+1);
    				}
    				if(index.size()==2)
    					break;
    			}

    			break;

    		}
    		else if(sum>target)
    			--right;
    		else
    			++left;

    	}
        return index;
    }
};