337. House Robber III
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
    int rob(TreeNode* root)
    {
        map<TreeNode*,int> cash;
        return value(root,cash);
    }
    int value(TreeNode* root,map<TreeNode*,int>& cash)
    {
        if(!root)   return 0;
        if(cash.count(root))    return cash[root];
        int val = 0;
        if(root->left)
            val+=value(root->left->left,cash)+value(root->left->right,cash);
        if(root->right)
            val+=value(root->right->left,cash)+value(root->right->right,cash);
        val = max(val + root->val,value(root->left,cash) + value(root->right,cash));
        cash[root] = val;
        return val;
    }
};