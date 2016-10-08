113. Path Sum II
哈哈哈，让我高兴一下，这道题一遍就AC了
//思路整理
//如果root不存在，直接返回空
//若root是叶子，若sum==root->val则将root->val加入curr并且把curr加入res;若不相等，那么无需添加，直接返回上一层
//若不是叶子节点，则转向左或右子树
vector<vector<int>> pathSum(TreeNode* root, int sum) {
           vector<vector<int>>  res;
           vector<int> cur = {};
           helper(root,sum,cur,res);
           return res;
        }
void helper(TreeNode* root,int sum,vector<int> curr,vector<vector<int>>& res)
{
    if(!root)   return;
    if(!root->left&&!root->right)
    {
        if(sum==root->val)
        {
            curr.push_back(root->val);
            res.push_back(curr);
        }
        else
        {
            return;
        }
    }
    else
    {
        curr.push_back(root->val);
        helper(root->left,sum-root->val,curr,res);
        helper(root->right,sum-root->val,curr,res);
    }
}
