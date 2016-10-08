92. Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head||!head->next||m==n)    return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy,*q = dummy;
        while(m-1)
        {
            p = p->next;
            --m;
        }
        while(n+1)
        {
            q = q->next;
            --n;
        }
        ListNode* pre = q;
        ListNode* cur = p->next;
        while(cur->next!=q)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        cur->next = pre;
        p->next = cur;
        return dummy->next;
    }
};