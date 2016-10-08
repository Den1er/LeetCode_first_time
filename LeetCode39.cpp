129. Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root,0,sum);
        return sum;
    }
    void helper(TreeNode* root,int s,int& sum)
    {
        if(!root)   return;
        if(!root->left&&!root->right)
        {
            s = 10*s+root->val;
            sum+=s;
        }
        if(root->left)
        {
            helper(root->left,10*s+root->val,sum);
        }
        if(root->right)
        {
            helper(root->right,10*s+root->val,sum);
        }
    }
    
};


class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
    int helper(TreeNode* root,int s)
    {
        if(!root)   return 0;
        if(!root->left&&!root->right)
        {
            s = s*10 + root->val;
            return s;
        }
        return helper(root->left,10*s+root->val)+
        helper(root->right,10*s+root->val);
        
    }
    
    
};