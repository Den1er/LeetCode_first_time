257. Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)    return res;
        helper(root,to_string(root->val),res);
        return res;
    }
    void helper(TreeNode* node,string s,vector<string>& one)
    {
        if(!node->left&&!node->right)
        {
            one.push_back(s);
            return;
        }
        if(node->left)  helper(node->left,s+"->"+to_string(node->left->val),one);
        if(node->right) helper(node->right,s+"->"+to_string(node->right->val),one);
        
    }
};