86. Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-1);
        if(!head||!head->next)  return head;
        dummy->next = head;
        ListNode* pre = dummy,*curr = head;
        ListNode* p = dummy;
        int length = 0;
        while(p->next)
        {
            p = p->next;
            ++length;
        }
        while(curr&&length)
        {
            if(curr->val<x)
            {
                curr = curr->next;
                pre = pre->next;
            }
            else
            {
                if(p!=curr)
                {
                    pre->next = curr->next;
                    p->next = curr;
                    curr->next = NULL;
                    
                    curr = pre->next;
                }
            }
            if(p->next)
            {
                p = p->next;
            }
            --length;
        }
        return dummy->next;
    }
};