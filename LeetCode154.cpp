572. Subtree of Another Tree
//先实现一个辅助函数判断两棵树是否相同，再暴力搜索出有没有一个子树是相同的，我想了可能有一个一个优化方法，先算出这棵树的高度，然后用队列遍历树，可以减少运算
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t)    return 1;
        if(!s)  return 0;
        if(isSame(s, t))
            return 1;
        else
        {
            
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
    bool isSame(TreeNode* r1, TreeNode* r2)
    {
        if(!r1 && !r2)  return 1;
        if(!r1 && r2 || !r2 && r1)  return 0;
        if(r1->val != r2->val)  return 0;
        return isSame(r1->left, r2->left) && isSame(r1->right, r2->right);
    }
};