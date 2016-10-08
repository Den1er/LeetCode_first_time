116. Populating Next Right Pointers in Each Node
全是自己写的哈哈哈
//解题思路
//目前想到的是建立二层vector，存每层的指针
//
void connect(TreeLinkNode *root) {
        vector<vector<TreeLinkNode*>> res;
        helper(root,res,1);
        for(int i = 0; i<res.size(); ++i)
        {
            for(int j = 0; j<res[i].size(); ++j)
            {
                if(j==res[i].size()-1)
                {
                    res[i][j]->next = NULL;
                }
                else
                {
                    res[i][j]->next = res[i][j+1];
                }
            }
        }
            }
void helper(TreeLinkNode* root,vector<vector<TreeLinkNode*>>& res,int level)
{
    if(!root)   return;
    if(res.size()<level)
    {
        vector<TreeLinkNode*> cur;
        res.push_back(cur);
    }
    res[level-1].push_back(root);
    helper(root->left,res,level+1);
    helper(root->right,res,level+1);
}
/******************************************/

void connect(TreeLinkNode* root)
{
    connect(root,NULL);


}
void connect(TreeLinkNode* root,TreeLinkNode* subling)
{
    if(!root)   return;
    else
    {
        root->next = subling;
    }
    connect(root->left,root->right);
    if(subling)
    {
        connect(root->right,subling->left);
    }
    else
    {
        connect(root->right,NULL);
    }
}