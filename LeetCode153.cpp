404. Sum of Left Leaves
//搜索整棵树
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)   return 0;
        int res = 0;
        search(root->left, 0, res);
        search(root->right, 1, res);
        return res;
    }
    void search(TreeNode* root, bool flag, int& sum)
    {
        if(!root)   return;
        if(!root->left && !root->right)
        {
            if(flag == 0)
                sum += root->val;
            else
                return;
        }
        if(root->left)
            search(root->left, 0, sum);
        if(root->right)
            search(root->right, 1, sum);
    }
};
