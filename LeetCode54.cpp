235. Lowest Common Ancestor of a Binary Search Tree
自己写的沿用了BST的思路，采用前序遍历找到节点与root的位置关系
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)    return NULL;
        if(!p)   return q;
        if(!q)   return p;
        if(whereis(root,p)+whereis(root,q)==2)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(whereis(root,p)+whereis(root,q)==-2)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else
        {
            return root;
        }
    }
    int whereis(TreeNode* root, TreeNode* p)
    {
        if(p==root) return 0;
        if(!root->left) return 1;
        if(!root->right)    return -1;
        stack<TreeNode*> s;
        s.push(root->left);
        while(!s.empty())
        {
            TreeNode* q = s.top();
            s.pop();
            if(q==p)    return -1;
            if(q->right)    s.push(q->right);
            if(q->left)     s.push(q->left);
        }
        s.push(root->right);
        while(!s.empty())
        {
            TreeNode* q = s.top();
            s.pop();
            if(q==p)    return 1;
            if(q->right)    s.push(q->right);
            if(q->left)     s.push(q->left);
        }
        return 999;
    }
};
/**********************/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q), *r = lowestCommonAncestor(root->right, p, q);
        if(l && r) return root;
        return l? l:r;
    }
};