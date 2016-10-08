95. Unique Binary Search Trees II
添加空指针这句话很重要，否则将无法进入循环
以及要特殊处理n==0的边界
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
        {
            vector<TreeNode*> res;
            return res;
        }
        return helper(1,n);
    }
    vector<TreeNode*> helper(int begin, int end)
    {
        vector<TreeNode*>   res;
        if(begin>end)
        {
            res.push_back(NULL);
            return res;
        }
        for(int i = begin; i<end+1; ++i)
        {
            vector<TreeNode*> l = helper(begin,i-1);
            vector<TreeNode*> r = helper(i+1,end);
            for(int j = 0; j<l.size(); ++j)
            {
                for(int k = 0; k<r.size(); ++k)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l[j];
                    root->right = r[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};