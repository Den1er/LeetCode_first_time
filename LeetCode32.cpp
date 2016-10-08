110. Balanced Binary Tree
bool isBalanced(TreeNode* root) {
           return treeheight(root)>=0; 
        }
int treeheight(TreeNode* root)
{
    if(!root)   return 0;
    int left = treeheight(root->left);
    int right = treeheight(root->right);
    if(left<0||right<0||abs(left-right)>1)  return -1;
    return (left>right?left:right)+1;

}

