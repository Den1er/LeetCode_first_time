vector<int> rightSideView(TreeNode* root) {
           vector<int> final;
           vector<vector<LinkNode*>> help;
           helper(root,help,1);
           for(int i = 0; i<help.size(); ++i)
           {
               int last = help[i].size()-1;
               final.push_back(help[i][last]);
           }
           return final;
        }
void helper(TreeNode* root,vector<vector<LinkNode*>>& res,int level)
{
        if(!root)   return;
        if(res.size()<level)
        {
               vector<LinkNode*> cur;
               res.push_back(cur);
               }
        res[level-1].push_back(root);
        helper(root->left,res,level+1);
        helper(root->right,res,level+1);
}

