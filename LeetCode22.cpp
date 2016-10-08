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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)   return result;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre;
        TreeNode* curr = root;
        while(!s.empty())
        {
            curr = s.top();
            if(curr->left&&pre!=curr->left&&pre!=curr->right)
            {
                s.push(curr->left);
            }
            else if(curr->right&&pre!=curr->right)
            {
                s.push(curr->right);
            }
            else
            {
                pre = curr;
                result.push_back(curr->val);
                s.pop();
            }
        }
        return result;
    }
};

145. Binary Tree Postorder Traversal