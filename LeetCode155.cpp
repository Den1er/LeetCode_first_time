124. Binary Tree Maximum Path Sum
//类似DP的思想，把所有子结构的最大值都遍历了一遍，如果左右子树，哪个的值大于零，都可以收入麾下。返回值代表从该节点到出发最大的路径
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
    int maxPathSum(TreeNode* root) {
        int sum_max = INT_MIN;
        dfs(root, sum_max);
        return sum_max;
    }
    int dfs(TreeNode* root, int& sum_max)
    {
        if(!root)   return 0;
        int l1 = dfs(root->left, sum_max);
        int l2 = dfs(root->right, sum_max);
        int sum = root->val;
        if(l1 > 0)  sum += l1;
        if(l2 > 0)  sum += l2;
        if(sum > sum_max)   sum_max = sum;
        return max(l1, l2) > 0 ? max(l1, l2) + root->val : root->val;
    }
};