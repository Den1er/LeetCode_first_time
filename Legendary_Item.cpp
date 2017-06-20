struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class solution{
public:
double legendaryitem(TreeNode* root)
{
     
}
void growup(TreeNode* root, int n, int num, bool just)  //root的value存成功的概率，n代表已有的装备，num代表没拿到装备的次数，just表示刚获取装备
{
    if(n == N)  return;
    if(root->val >= 100)
    {
        TreeNode* lchild = new TreeNode(P / 2); 
        root->left = lchild;
        growup(lchild, n + 1, 0, 1);
    }
    else
    {
        if(just == 1)
        {
            TreeNode* lchild = new TreeNode(P / 2);
            TreeNode* rchild = new TreeNode(100 - P/ 2 + num * Q);
            root->left = lchild;
            root->right = rchild;
            growup(lchild, n + 1, 0, 1);
            growup(rchild, n, num + 1, 0);
        }
        else
        {
            TreeNode* lchild = new TreeNode(P / 2);
            TreeNode* rchild = new TreeNode(100 - r->val + num * Q);
            root->left = lchild;
            root->right = rchild;
            growup(lchild, n + 1, 0, 1);
            growup(rchild, n, num + 1, 0);
        }
    }
}
private:
    const int N;
    const int P;
    const int Q;
};
