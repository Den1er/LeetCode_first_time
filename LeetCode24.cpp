230. Kth Smallest Element in a BST

中序遍历整个树，存在一个vector中

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(!s.empty()||p)
        {
            if(p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                res.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        return res[k-1];
    }
};