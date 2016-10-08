148. Sort List
单链表排序用归并，双链表排序用快排，先把链表分半，分治的方法，最后合并两个有序链表
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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)  return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* r_head = slow->next;
        slow->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(r_head);
        return mergelist(l1,l2);
    }
    ListNode* mergelist(ListNode* l_h,ListNode* r_h)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while(l_h||r_h)
        {
            if(l_h&&r_h)
            {
                if(l_h->val>r_h->val)
                {
                    p->next = r_h;
                    p = p->next;
                    r_h = r_h->next;
                }
                else
                {
                    p->next = l_h;
                    p = p->next;
                    l_h = l_h->next;
                }
            }
            else if(!l_h)
            {
                p->next = r_h;
                p = p->next;
                r_h = r_h->next;
            }
            else
            {
                p->next = l_h;
                p = p->next;
                l_h = l_h->next;
            }
        }
        return dummy->next;
    }
};