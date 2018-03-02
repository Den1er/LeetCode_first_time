513. Find Bottom Left Tree Value
//本题解法就是递归遍历，只不过在每一层带上一个参数，方便于找到最深的那一层
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
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        leftmost = root->val;
        dfs(root, 0);
        return leftmost;
    }
private:
    int maxDepth;
    int leftmost;
    void dfs(TreeNode* root, int depth)
    {
        if(!root->left && !root->right)
        {
            if(depth > maxDepth)
            {
                leftmost = root->val;
                maxDepth = depth;
            }
            return;
        }
        if(root->left)  dfs(root->left, depth + 1);
        if(root->right)  dfs(root->right, depth + 1);
    }
};

