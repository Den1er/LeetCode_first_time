tion for a binary tree node.
 * struct TreeNode {
     *  *     int val;
     *   *     TreeNode *left;
     *    *     TreeNode *right;
     *     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     *      * };
*       */
class Solution {
public:
           vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
                             vector<vector<int>> res;
                                           zigzag(root,1,res,1);
                                                         return res;
                                                                    }
              void zigzag(TreeNode* r,int level,vector<vector<int>>& res,bool ltr)
                     {
                                if(!r)  return;
                                       if(level>res.size())    res.push_back(vector<int>());
                                             if(ltr)
                                                       {
                                                                     res[level-1].push_back(r->val);
                                                                           }
                                                   else
                                                             {
                                                                           res[level-1].insert(res[level-1].begin(),r->val);
                                                                                 }
                                                         zigzag(r->left,level+1,res,!ltr);
                                                               zigzag(r->right,level+1,res,!ltr);
                                                                 }

};
103. Binary Tree Zigzag Level Order Traversal