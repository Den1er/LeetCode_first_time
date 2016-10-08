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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelO(result,1,root);
        return result;
    }
    void levelO(vector<vector<int>> &res,int level,TreeNode* p)
    {
        if(!p)  return;
        if(level>res.size())
        {
            res.push_back(vector<int>());
            
        }
        res[level-1].push_back(p->val);
        levelO(res,level+1,p->left);
        levelO(res,level+1,p->right);
    }
};

102. Binary Tree Level Order Traversal