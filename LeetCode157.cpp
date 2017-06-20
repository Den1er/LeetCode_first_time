501. Find Mode in Binary Search Tree
//先使用中序遍历，将整个树排好序，接着处理这个排好序的数组，记录连续数最大的元素
class Solution {
public:
    int count;
    int max_count = 0;
    vector<int> set;
    vector<int> res;

    vector<int> findMode(TreeNode* root) {
        inorder(root); 
        return res;
    }
    void inorder(TreeNode* root)
    {
        if(!root)   return;
        inorder(root->left);
        helper(root->val);
        inorder(root->right);
    }
    void helper(int val)
    {
        
        if(set.empty() || val != set.back()) 
        {
            set.push_back(val);
            count = 1;
        }
        else
        {
            ++count;
        }
        if(count == max_count)
            res.push_back(val);
        else if(count > max_count)
        {
            res.clear();
            res.push_back(val);
        }
        max_count = max_count > count ? max_count : count;
        
    }
};
