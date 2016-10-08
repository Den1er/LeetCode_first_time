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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        s(result,1,root);
        std::reverse(result.begin(),result.end());
        return result;
        
    }
    void s(vector<vector<int>>& vec,int lev,TreeNode* r)
    {
        if(!r)  return;
        if(lev>vec.size())
        {
            vec.push_back(vector<int>());
        }
        vec[lev-1].push_back(r->val);
        s(vec,lev+1,r->left);
        s(vec,lev+1,r->right);
    }
    
};


107. Binary Tree Level Order Traversal II