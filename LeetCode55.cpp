222. Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if(!root)    return 0;
        int l_len = 0;
        int r_len = 0;
        TreeNode* lt = root->left;
        TreeNode* rt = root->right;
        while(lt)
        {
            ++l_len;
            lt = lt->left;
        }
        while(rt)
        {
            ++r_len;
            rt = rt->right;
        }
        if(r_len==l_len)
        {
            return pow(2,l_len+1)-1;
        }
        else
            return countNodes(root->left)+countNodes(root->right)+1;
    }
};