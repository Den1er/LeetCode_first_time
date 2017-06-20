437. Path Sum III
//函数dfs表示从node出发，所有合为sum的路径，以后这道题还是需要再写一遍
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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        if(!root)   return res;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int dfs(TreeNode* node, int sum)
    {
        if(!node)   return 0;
        int res = 0;
        if(node->val == sum)
        {
            ++res;
        }
        return res + dfs(node->left, sum - node->val) + dfs(node->right, sum - node->val);
    }
};