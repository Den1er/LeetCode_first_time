109. Convert Sorted List to Binary Search Tree
超时了，在一个很大的数组上，需要优化
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while(p)
        {
            p = p->next;
            ++n;
        }
        return helper(head,0,n-1);
    }
    TreeNode* helper(ListNode* head, int begin, int end)
    {
        if(!head)    return NULL;
        if(begin>end) return NULL;
        //  if(begin==end)    return new TreeNode(head->val);
        int mid = end + (begin-end)/2;
        int n = mid;
        ListNode* p = head;
        while(n)
        {
            p = p->next;
            --n;
        }
        TreeNode* root = new TreeNode(p->val);
        root->left = helper(head,begin,mid-1);
        root->right = helper(head,mid+1,end);
        return root;
        
        
    }
};

自下而上
这是一中自底向上的方法。
在递归中传的都是同一个链表，只是这个链表的节点不停往前走；而真正决定性变化的是区间；
可以看到，每次递归调用开始时，节点指针都指向区间第一个，结束时节点的指针指向区间末尾的后一个。
每次递归调用时，分成左右两部分，左边构造完时，正好指针指向mid，创建一下root，继续构造右部分子树。
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head){
        if(head == NULL){
            return NULL;
        }//if
        int count = 0;
        ListNode *p = head;
        // 统计链表个数
        while(p){
            p = p->next;
            count++;
        }//while
        return SortedListToBST(head,0,count-1);
    }
private:
    TreeNode *SortedListToBST(ListNode*& node,int start,int end){
        if (start > end){
            return NULL;
        }//if
        // 中间节点
        int mid = start + (end - start)/2;
        // 左子树
        TreeNode *leftSubTree = SortedListToBST(node, start, mid-1);
        TreeNode *root = new TreeNode(node->val);
        root->left = leftSubTree;
        node = node->next;
        // 右子树
        TreeNode *rightSubTree = SortedListToBST(node, mid+1, end);
        root->right = rightSubTree;
        return root;
    }
};