111. Minimum Depth of Binary Tree
int minDepth(TreeNode* root){
    if(!root)   return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if(!root->left) return left+1;
    else if(!root->right)   return right+1;
    else
    return min(left,right)+1;
}
