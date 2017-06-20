563. Binary Tree Tilt
//两个递归
class Solution {
public:
    int findTilt(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
    int sumoftree(TreeNode* root)
    {
        if(!root)   return 0;
        if(!root->left && !root->right) return root->val;
        int res = val;
        if(root->left)  res += sumoftree(root->left);
        if(root->right) res += sumoftree(root->right);
        return res;
    }
    void dfs(TreeNode* node, int& sum)
    {
        if(!node)   return;
        sum += abs(sumoftree(node->left) - sumoftree(node->right));
        dfs(node->left, sum);
        dfs(node->right, sum);
    }
};
