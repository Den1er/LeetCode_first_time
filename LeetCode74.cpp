82. Remove Duplicates from Sorted List II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)  return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy->next;
        ListNode* q = p;
        while(q->next&&q->next->val==p->val)//要先判断有没有下一个，再判断值是否相同，否则会报错
        {
            q = q->next;
        }
        q = q->next;
        if(q==p->next)
        {
            p->next = deleteDuplicates(p->next);
        }
        else
        {
            dummy->next = deleteDuplicates(q);
        }
        return dummy->next;
    }
};