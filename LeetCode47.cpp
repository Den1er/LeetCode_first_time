114. Flatten Binary Tree to Linked List
public:
    void flatten(TreeNode* root) {
        if(!root)   return;
        
        flatten(root->left);
        flatten(root->right);

        if(!root->left) return;

        TreeNode* p = root->left;
        while(p->right)  p = p->right;
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
            }
};
