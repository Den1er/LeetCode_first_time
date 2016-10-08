117. Populating Next Right Pointers in Each Node II
class Solution {
public:
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
    
};
/***************************************************/
递归解法
void connect(TreeLinkNode *root) {
    if(!root) return;
    
    //If left and right exist, we will find their nextNodes with the next node function
    if(root->left) root->left->next = getNext(root, root->left, 1);
    if(root->right) root->right->next = getNext(root, root->right, 0);
    
    //Call it on root->right before root->left because there are some cases
    //where a next node hasn't been set on a parent level, so when we try to find the
    //next node, it will just be nullptr.
    connect(root->right);
    connect(root->left);
}

//If we are a left node and the right node exists, we can just return the right
//node. Otherwise, we will go to the root and continue through the root level
//until we find a child node that exists and return that child. Otherwise, return nullptr
TreeLinkNode *getNext(TreeLinkNode *root, TreeLinkNode *left, bool isLeft) {
    if(isLeft && root->right) return root->right;
    TreeLinkNode *next = root->next;
    while(next) {
        if(next->left) return next->left;
        if(next->right) return next->right;
        next = next->next;
    }
    return nullptr;
}
/********************************/