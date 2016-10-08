173. Binary Search Tree Iterator
意思就是中序遍历啊啊啊啊啊啊啊啊
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<TreeNode*> bowl;
    int index = 0;
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(!s.empty()||p)
        {
            if(p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                bowl.push_back(p);
                s.pop();
                p = p->right;
            }
        }
        
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(index<bowl.size())    return true;
        else
        {
            return false;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        return bowl[index++]->val;
    }
};


/**
 *  * Your BSTIterator will be called like this:
 *   * BSTIterator i = BSTIterator(root);
 *    * while (i.hasNext()) cout << i.next();
 *     */
