606. Construct String from Binary tree
//本题不能构建一个辅助函数，否则会超时，思路是左孩子若为空，那么要考虑右孩子是否存在，不存在就直接返回，存在则需要加括号
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
    string tree2str(TreeNode* t) {
        if(!t)  return "";
        //return helper(t);
        string s = to_string(t->val);
        if(!t->left)
        {
            if(!t->right)
                return s;
            else
                return s + "()(" + tree2str(t->right) + ")";
        }
        else
        {
           if(!t->right)
               return s + "(" + tree2str(t->left) + ")";
           else
               return s + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
        }

    }

   
};
