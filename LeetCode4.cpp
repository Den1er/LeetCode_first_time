/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Remove Linked List Elements
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        //two pointers
        //一个指针负责从头开始，另一指针遍历链表，前一指针q用于判断是否相等，只有当
        //p判断不为敏感变量时，q才向后移动
        ListNode *front;
        front = new ListNode(-1);
        front->next = head;
        ListNode *p = head;// used for every word
        listNode *q = front;
        while(p)
        {
            if(p->val==val)//delete the node which pointer p points to.
            {
                q->next = p->next;

            }
            else
            {
                q = q->next;

            }
            p = p->next;

        }

        ListNode *a = front->next;
        delete front;
        return a;

     /*   if (head == NULL) return NULL;
    if (val == head->val) return removeElements(head->next,val);
    head->next = removeElements(head->next,val);
    return head;    */
    }
};
