99. Recover Binary Search Tree
This question appeared difficult to me but it is really just a simple in-order traversal! I got really frustrated when other people are showing off Morris Traversal which is totally not necessary here.

Let's start by writing the in order traversal:
private void traverse (TreeNode root) {
    if (root == null)
        return;
    traverse(root.left);
    // Do some business
    traverse(root.right);
}
What is the business we are doing here?
We need to find the first and second elements that are not in order right?

How do we find these two elements? For example, we have the following tree that is printed as in order traversal:

6, 3, 4, 5, 2

We compare each node with its next one and we can find out that 6 is the first element to swap because 6 > 3 and 2 is the second element to swap because 2 < 5.

Really, what we are comparing is the current node and its previous node in the "in order traversal".

Let us define three variables, firstElement, secondElement, and prevElement. Now we just need to build the "do some business" logic as finding the two elements.
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
    TreeNode* firstelement = NULL;
    TreeNode* secondelement = NULL;
    TreeNode* preelement = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = firstelement->val;
        firstelement->val = secondelement->val;
        secondelement->val = temp;
    }
    void inorder(TreeNode* root)
    {
        if(!root)   return;
        inorder(root->left);
        if(firstelement==NULL&&preelement->val>=root->val)
        {
            firstelement = preelement;
        }
        if(firstelement!=NULL&&preelement->val>=root->val)
        {
            secondelement = root;
        }
        preelement = root;
        inorder(root->right);
    }
};