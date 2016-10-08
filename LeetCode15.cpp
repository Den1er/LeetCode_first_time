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
    int maxDepth(TreeNode* root) {
        if(root==NULL)  return 0;
        int depth_l = maxDepth(root->left);
        int depth_r = maxDepth(root->right);
        return depth_l>depth_r?depth_l+1:depth_r+1;
    }
};


104. Maximum Depth of Binary Tree