105. Construct Binary Tree from Preorder and Inorder Traversal  QuestionEditorial Solution
内存爆了，但是小数据量是成立的
形参加上引用标志就AC了，因为引用不需要复制副本
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int pre_begin,int pre_end,int in_begin,int in_end)
    {
        if(preorder.empty()&&inorder.empty()) return NULL;
        if(pre_begin>pre_end)   return NULL;
        if(in_begin>in_end) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_begin]);
        int i = in_begin;
        for( i ; i<in_end+1; ++i)
        {
            if(preorder[pre_begin]==inorder[i])
                break;
        }
        root->left = helper(preorder,inorder,pre_begin+1,pre_begin+i-in_begin+1,in_begin,i-1);
        root->right = helper(preorder,inorder,i+1+pre_begin-in_begin,pre_end,i+1,in_end);
        return root;
    }
};