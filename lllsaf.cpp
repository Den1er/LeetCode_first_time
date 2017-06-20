class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)   return 1;
        return (abs(depth(root->left - root->right) < 2 ? 1 : 0)) && isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode* root)
    {
        if(!root)   return 0;
        if(!root->left && !root->right) return 1;
        int l1 = 0, l2 = 0;
        l1 = depth(root->left);
        l2 = depth(root->right);
        return 1 + max(l1, l2); 
    }
};
