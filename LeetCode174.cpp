515. Find Largest Value in Each Tree Row
//层序遍历，遍历一遍，找到最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root)   return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int currMax = INT_MIN;
            int len = q.size();
            for(int i = 0; i < len; ++i)
            {
                TreeNode* tmp = q.front();
                if(tmp->val > currMax)
                    currMax = tmp->val;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                q.pop();
            }
            res.push_back(currMax);
        }
        return res;
    }
};

