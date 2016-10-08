106. Construct Binary Tree from Inorder and Postorder Traversal
奇怪，这个没报错,一遍就AC；
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,postorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int post_begin, int post_end, int in_begin, int in_end)
    {
        if(inorder.empty()&&postorder.empty())  return NULL;
        if(post_begin>post_end||in_begin>in_end)    return NULL;
        
        TreeNode* root = new TreeNode(postorder[post_end]);
        
        int i = in_begin;
        for(; i<in_end;++i)
        {
            if(postorder[post_end]==inorder[i])
                break;
        }
        root->right = helper(inorder,postorder,post_end-in_end+i,post_end-1,i+1,in_end);
        root->left = helper(inorder,postorder,post_begin,post_end-in_end+i-1,in_begin,i-1);
        return root;
    }
};