112. Path Sum
bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        if(!root->left&&!root->right)   
        {
            if(root->val==sum)
            {
                return true;
            }
        }
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->right);
        }
