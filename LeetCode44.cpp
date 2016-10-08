bool isValidBST(TreeNode* root)
{
    helper(root,LONG_MIN,LONG_MAX);
}
bool helper(TreeNode* root,long low,long high)
{
    if(!root)   return 1;
    return root->val<high&&root->val>low&&helper(root->left,low,root->val)
        &&helper(root->right,root->val,high);
}
