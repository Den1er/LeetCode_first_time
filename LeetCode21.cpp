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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(!s.empty()||p)
        {
            if(p!=NULL)
            {
                s.push(p);
                p = p->left;
            }
            if(p==NULL)
            {
                p = s.top();
                result.push_back(p->val);
                s.pop();
                p = p->right;
            }
            
        }
        return result;
    }
};

94. Binary Tree Inorder Traversal